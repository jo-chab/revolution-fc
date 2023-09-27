<?php    include("_includes/session_test.inc");    include("_includes/_revolutionfc.inc");        $categorySelectedUrl = isset($_GET['category']) ? intval($_GET['category']) : 0;// Function to fetch and display documents for a given subcategory    function displayDocumentsForSubcategory($db, $subcategory)    {        $stmt = $db->prepare('SELECT * FROM DOCS_club WHERE doc_subcategory = ? ORDER BY doc_title ASC');        $stmt->execute([$subcategory]);        $results = $stmt->fetchAll(PDO::FETCH_ASSOC);                if (count($results) > 0) {            echo "<h4>" . getSubcategoryName($db, $subcategory) . "</h4>";                        // Fetch subcategory_text from the database            $subcategoryText = getSubcategoryText($db, $subcategory);                        // Display the subcategory text if it's not empty            if (!empty($subcategoryText)) {                echo "<p>" . nl2br(stripslashes($subcategoryText)) . "</p>";            }                        echo "<ul class='list-docs'>";            foreach ($results as $result) {                $link = $result['doc_link'];                $title = nl2br(stripslashes($result['doc_title']));                                echo "                <li>                    <span class='docs-title'>$title</span>                    <a class='btn-download icon i-download mobile-icon-only' href='$link' target='_blank'><span>Télécharger</span></a>                </li>            ";            }            echo "</ul>";        } else {        }    }// Function to get the subcategory name from the database    function getSubcategoryName($db, $subcategory)    {        $stmt = $db->prepare('SELECT subcategory_name FROM DOCS_subcategory WHERE id_subcategory = ?');        $stmt->execute([$subcategory]);        return $stmt->fetchColumn();    }// Function to get the subcategory text from the database    function getSubcategoryText($db, $subcategory)    {        $stmt = $db->prepare('SELECT subcategory_text FROM DOCS_subcategory WHERE id_subcategory = ?');        $stmt->execute([$subcategory]);        return $stmt->fetchColumn();    }?>    <!doctype html><html><head><meta charset="UTF-8"><?php    if ($categorySelectedUrl == 1) {        echo "<title>S&eacute;curit&eacute; des enfants</title>";    } elseif ($categorySelectedUrl == 2) {        echo "<title>Documents de référence pour les parents</title>";    }?><?php    include("_includes/head.inc");    echo "<body>";    include("_includes/header.inc");?>        <section>                <article class="wrapper-text">                        <?php                                if ($categorySelectedUrl == 1) {                    echo "            <h1 class='main-heading'>S&eacute;curit&eacute;</h1>            <p>La s&eacute;curit&eacute; des enfants est une priorit&eacute; pour notre club du Révolution                F.C. Ainsi, le club s’est doté de Politiques, d’un Code de conduite et de déontologie et de diverses                règles                pour s’assurer de la sécurité de ses membres. Ces normes de conduite sont basées sur les principes                et les valeurs morales et fondamentales auxquels s’identifient et se rallient tous les membres du Révolution F.C. Celles-ci établissent nos devoirs, nos responsabilités et viennent encadrer la                conduite et les rapports entre tous les membres, leurs intervenants et le public en général.</p>            <h4>Personne ressource</h4>            <p>Le club s’est doté d’un responsable de la sécurité et la protection des enfants afin de supporter les membres dans l’application de ces règles pour la protection des enfants. Le responsable de la sécurité et la protection des enfants pour le Révolution FC est :<br>                Moustapha Sall – Directeur Général<br>                <a href='mailto:Moustapha.sall@revolutionfc.ca' class='inline-link'>Moustapha.sall@revolutionfc.ca</a></p>                    ";                } elseif ($categorySelectedUrl == 2) {                    echo "            <h2>Documents de référence pour les parents</h2>            <p>Cette section vous donne les liens vers les documents importants. Prenez le temps de parcourir ces                documents et si vous avez des questions, n’hésitez pas à nous contacter à <a class='inline-link' href='mailto:info@revolutionfc.ca'>info@revolutionfc.ca</a>.</p>                    ";                }                            ?>                        <div class="w-list-docs">                <?php                    // Fetch subcategories for the selected category_reference                    $stmt = $db->prepare('SELECT id_subcategory FROM DOCS_subcategory WHERE reference_category = ?');                    $stmt->execute([$categorySelectedUrl]);                    $subcategories = $stmt->fetchAll(PDO::FETCH_COLUMN);                                        // Loop through these subcategories and display documents                    foreach ($subcategories as $subcategory) {                        displayDocumentsForSubcategory($db, $subcategory);                    }                ?>            </div>                </article>            </section><?php include("_includes/footer.inc") ?>