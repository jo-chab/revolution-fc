<?php
    include("../_includes/session_test.inc");
    include("../_includes/_revolutionfc.inc");
?>
<!doctype html>
<html lang="fr">
<head>

<meta charset="UTF-8">

<title>Politiques</title>

<?php
    include("../_includes/head.inc");
    echo "<body>";
    include("../_includes/header.inc");
?>

<section>

    <article class="wrapper doc-container">

        <h2 class="section-title">Liste des politiques du club</h2>
        <ul class="documents-list">
            <?php

            $stmt = $db->prepare('SELECT * FROM DOCS where doc_cat = 102 order by doc_name ASC');
            $stmt->execute();
            $results = $stmt->fetchAll(PDO::FETCH_ASSOC);

            foreach($results as $result)
            {
                $link=$result['doc_link'];
                $link="../".$link;
                $titre=nl2br(stripslashes($result['doc_name']));

                echo "
                <a href='$link' target='_blank'>
                <li>
                    <h4 class='doc-list-title'>$titre</h4>
                    <div class='btn-primary cta-download-2'><span class='is-hide-mobile'>T&eacute;l&eacute;charger le document</span></div>
                </li>
                </a>
                ";
            }

            ?>
        </ul>


    </article>

</section>







<?php include("../_includes/footer.inc") ?>
