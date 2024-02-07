<?php
    $element = $_GET['t'];
    unset($_GET);
    
    $sql1 = $db->prepare("SELECT * FROM TOURNAMENT WHERE id_tournament = ? ");
    $sql1->execute([$element]);
    
    while ($curseur1 = $sql1->fetch()) {
        extract($curseur1);
        
        $name = nl2br(stripslashes($tournament_name));
        $desc = nl2br(stripslashes($tournament_desc));
        $texte = nl2br(stripslashes($tournament_text));
        $texte = str_replace("<br /><br />", "", $texte);
        $texte = str_replace("<br />", "", $texte);
    }
    
    $supprElement = 1;
    $actionForm = "action_tournament_delete.php";
    $supprText = 'Supprimer le tournoi';
?>

<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Modifier <?php echo $name ?></h4>
    </div>
    
    <div class="dashboard-content">
        
        <form method="post" action="action_tournament_update" enctype="multipart/form-data">
            <div class="d-form-wrapper">
                
                <input name="element" type="hidden" value="<?php echo $element ?>">
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Nom du tournoi (max : 40 caractères) - ceci sera affiché dans le menu</label>
                        <input id="zt_name" name="zt_name" type="text" maxlength="40" value="<?php echo $name ?>"
                               required>
                    </div>
                </div>
                <div class="form-row column">
                    <label>Titre en-tete (max : 256 caractères)</label>
                    <input id="zt_desc" name="zt_desc" type="text" maxlength="256" value="<?php echo $desc ?>">
                </div>
                
                
                <!-- Include TinyMCE library -->
                <script src="https://cdn.tiny.cloud/1/ww9qtqggrif3pyqjvuxyx5ee7lwdmh1857eqzsvb3o2f1d3f/tinymce/5/tinymce.min.js" referrerpolicy="origin"></script>
                
                <!-- Initialize TinyMCE on your textarea -->
                <script>
                    tinymce.init({
                        selector: 'textarea#ta_tournoi',
                        width: '100%',
                        min_height: 500,
                        plugins: 'lists link table paste',
                        toolbar: 'undo redo | styleselect | paste bold italic underline | bullist numlist | link table',
                        paste_as_text: true,

                        style_formats: [
                            {
                                title: 'Texte', items: [
                                    { title: 'titre', format: 'h3' },
                                    { title: 'Titre de liste', format: 'h4' },
                                    { title: 'Paragraphe', format: 'p' }
                                ]
                            },
                            {
                                title: 'Align', items: [
                                    {title: 'Left', format: 'alignleft'},
                                    {title: 'Center', format: 'aligncenter'},
                                    {title: 'Right', format: 'alignright'}
                                ]
                            }
                        ],
                        // The following option is used to append style formats rather than overwrite the default style formats.
                        style_formats_merge: false,
                        menubar: false
                    });
                </script>
                
                <div class="form-row column">
                    <label>Texte :</label>
                    <?php include("text-panel-tournoi.inc"); ?>
                    <textarea id="ta_tournoi" name="ta_tournoi" required><?php echo $texte ?></textarea>
                </div>
                
                <div class="form-row column">
                    <label>Photo actuelle</label>
                    <?php
                        echo "<div class='actu-img-upload'><img src='../$tournament_img' alt='$name' /></div>";
                    ?>
                </div>
                
                <div class="form-row column">
                    <label>Mettre à jour l'image</label>
                    <ul class="file-list">
                        <li class="file-list-element">
                            <div class="dashboard-file-box">
                                <input type="file" name="f_photo_tournoi" id="f_photo_tournoi" class="inputfile"/>
                                <label for="f_photo_tournoi"
                                       class="upload-file-btn"><span>Télécharger nouvelle image</span></label>
                            </div>
                            <script src="/js/custom-file-input.js"></script>
                        </li>
                    </ul>
                    <h6>Attention les dimensions de l'image ne doivent pas dépasser 1200x800
                        px</h6>
                    <h6>Pensez également à réduire a taille de votre fichier pour améliorer
                        les performances de votre site.</h6>
                </div>
            
            </div>
            <div class="d-form-cta">
                <div class="btn-primary small btn-revert icon mobile-icon-only"><span>Effacer</span></div>
                <div class="btn-primary small btn-confirm icon mobile-icon-only"><span>Mettre à jour</span></div>
            </div>
        
        </form>
    
    </div>
</div>

<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Gérer les catégories pour <?php echo $name ?></h4>
    </div>
    
    <div class="dashboard-content">
        
        <div class="btn-primary btn-add small icon mobile-icon-only i-more js-content-add"><a>Ajouter une categorie</a></div>
        
        <?php include("../_includes/admin_tournament_category-add.inc"); ?>
        
        <ul class="dashboard-list">
            
            <?php
                
                $sql2 = $db->prepare('select * from TOURNAMENT_CATEGORIES where select_tournament = ? order by id_t_category ASC');
                $sql2->execute([$element]);
                
                $results2 = $sql2->fetchAll(PDO::FETCH_ASSOC);
                foreach ($results2 as $result) {
                    $id_category = $result['id_t_category'];
                    $soccer = nl2br(stripslashes($result['t_category_type']));
                    $category = nl2br(stripslashes($result['t_category_age']));
                    
                    echo "
            <li class='dashboard-list-elements layout-col-3'>
                <div class='list-cta content-icon'>
                      <form action='action_tournoi_category_delete' method='post'>
                        <input type='hidden' name='num_category' value='$id_category'>
                        <input type='hidden' name='num_tournoi' value='$element'>
                        <div class='btn-tertiary btn-text small btn-delete icon mobile-icon-only'></div>
                    </form>
                </div>
                <div class='element-title content-element'>$category – $soccer</div>
                <div class='list-cta content-btn'>
                    <form action='index.php?p=83' method='post'>
                        <input type='hidden' name='num_category' value='$id_category'>
                        <input type='hidden' name='num_tournoi' value='$element'>
                        <div class='btn-primary small btn-update icon mobile-icon-only'><span>Modifier</span></div>
                    </form>
                </div>
            </li>
                                ";
                    
                }
            ?>
        
        </ul>
    
    </div>
</div>