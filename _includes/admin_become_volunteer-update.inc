<?php
    
    $sql1 = $db->prepare("SELECT * FROM VOLUNTEER WHERE id_volunteer = ? ");
    $sql1->execute([1]);
    
    if ($curseur1 = $sql1->fetch()) {
        $title = nl2br(stripslashes($curseur1['volunteer_title']));
        $volunteer_img = nl2br(stripslashes($curseur1['volunteer_img']));
        $texte = nl2br(stripslashes($curseur1['volunteer_text']));
        $texte = str_replace("<br /><br />", "", $texte);
        $texte = str_replace("<br />", "", $texte);
    } else {
        $name = "Tournament Not Found";
        $desc = "";
        $texte = "";
    }
?>


<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Modifier <?php echo $title ?></h4>
    </div>
    
    <div class="dashboard-content">
        
        <form method="post" action="action_become_volunteer_update" enctype="multipart/form-data">
            <div class="d-form-wrapper">
                
                <input name="element" type="hidden" value="1">
                
                <div class="form-row column">
                    <label>Nom du tournoi (max : 40 caractères) - ceci sera affiché dans le menu</label>
                    <input id="zt_name" name="zt_name" type="text" maxlength="40" value="<?php echo $title ?>"
                           required>
                </div>
                
                <!-- Include TinyMCE library -->
                <script src="https://cdn.tiny.cloud/1/ww9qtqggrif3pyqjvuxyx5ee7lwdmh1857eqzsvb3o2f1d3f/tinymce/5/tinymce.min.js" referrerpolicy="origin"></script>
                
                <!-- Initialize TinyMCE on your textarea -->
                <script>
                    tinymce.init({
                        selector: 'textarea#ta_benevoles',
                        width: '100%',
                        min_height: 500,
                        plugins: 'lists link table paste',
                        toolbar: 'undo redo | styleselect | paste bold italic underline | bullist numlist | link table',
                        paste_as_text: true,

                        style_formats: [
                            {
                                title: 'Texte', items: [
                                    {title: 'titre', format: 'h3'},
                                    {title: 'Titre de liste', format: 'h4'},
                                    {title: 'Paragraphe', format: 'p'}
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
                    <textarea id="ta_benevoles" name="ta_benevoles" required><?php echo $texte ?></textarea>
                </div>
                
                <div class="form-row column">
                    <label>Photo actuelle</label>
                    <?php
                        echo "<div class='actu-img-upload'><img src='/$volunteer_img' alt='$title' /></div>";
                    ?>
                </div>
                
                <div class="form-row column">
                    <label>Mettre à jour l'image</label>
                    <ul class="file-list">
                        <li class="file-list-element">
                            <div class="dashboard-file-box">
                                <input type="file" name="f_photo_v" id="f_photo_v" class="inputfile"/>
                                <label for="f_photo_v"
                                       class="upload-file-btn"><span>Télécharger nouvelle image</span></label>
                            </div>
                            <script src="/js/custom-file-input.js"></script>
                        </li>
                    </ul>
                    <h6>Attention les dimensions de l'image ne doivent pas dépasser 2000x1200
                        px et 2Mo en taille de fichier</h6>
                    <h6>Pensez à réduire a taille ou la qualité de votre fichier pour améliorer
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