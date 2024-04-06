<?php
    
    $sql1 = $db->prepare("SELECT * FROM VOLUNTEER_xp WHERE id_volunteer_xp = ? ");
    $sql1->execute([2]);
    
    if ($curseur1 = $sql1->fetch()) {
        $texte = nl2br(stripslashes($curseur1['xp_testimony']));
        $texte = str_replace("<br /><br />", "", $texte);
        $texte = str_replace("<br />", "", $texte);
    } else {
        $texte = "Text Not Found";
    }
?>


<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Modifier la page Experience communautaire</h4>
    </div>
    
    <div class="dashboard-content">
        
        <form method="post" action="action_volunteer_xp_update" enctype="multipart/form-data">
            <div class="d-form-wrapper">
                
                <input name="element" type="hidden" value="2">
                
                <!-- Include TinyMCE library -->
                <script src="https://cdn.tiny.cloud/1/ww9qtqggrif3pyqjvuxyx5ee7lwdmh1857eqzsvb3o2f1d3f/tinymce/5/tinymce.min.js" referrerpolicy="origin"></script>
                
                <!-- Initialize TinyMCE on your textarea -->
                <script>
                    tinymce.init({
                        selector: 'textarea#ta_benevoles',
                        width: '100%',
                        min_height: 500,
                        plugins: 'lists link paste',
                        toolbar: 'undo redo | styleselect | paste ',
                        paste_as_text: true,

                        style_formats: [
                            {
                                title: 'Texte', items: [
                                    {title: 'Citation', format: 'blockquote'},
                                    {title: 'Auteur', format: 'h4'},
                                    {title: 'Fonction', format: 'h5'}
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
            
            </div>
            <div class="d-form-cta">
                <div class="btn-primary small btn-revert icon mobile-icon-only"><span>Effacer</span></div>
                <div class="btn-primary small btn-confirm icon mobile-icon-only"><span>Mettre à jour</span></div>
            </div>
        
        </form>
    
    </div>
</div>