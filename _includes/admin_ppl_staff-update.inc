<?php
    
    $selected = $_POST['element'];
    unset($_POST);
    
    $stmt = $db->prepare("SELECT * FROM MEMBERS_STAFF WHERE id_member = ? ");
    $stmt->execute([$selected]);
    
    while ($curseur1 = $stmt->fetch()) {
        extract($curseur1);
    }

?>

<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Modifier les informations – <?php echo nl2br(stripslashes($member_name)) ?></h4>
    </div>
    
    
    <div class="dashboard-content">
        <form method="post" action="action_ppl_staff_update" enctype="multipart/form-data">
            <div class="d-form-wrapper">
                
                <input name="element" type="hidden" value="<?php echo $selected ?>">
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Nom de la personne (max 80 caract&egrave;res) :</label>
                        <input id="zt_name" name="zt_name" type="text" maxlength="80"
                               value="<?php echo nl2br(stripslashes($member_name)) ?>" required>
                    </div>
                    <div class="form-row column">
                        <label>Texte descriptif (max XX caract&egrave;res) :</label>
                        <input id="zt_desc" name="zt_desc" type="text" maxlength="30"
                               value="<?php echo nl2br(stripslashes($member_legend)) ?>">
                    </div>
                </div>
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Fonction (max 80 caract&egrave;res) :</label>
                        <input id="zt_function" name="zt_function" type="text" maxlength="80"
                               value="<?php echo nl2br(stripslashes($member_function)) ?>" required>
                    </div>
                    <div class="form-row column">
                        <label>Email associé à la personne :</label>
                        <input id="zt_email" name="zt_email" type="email" maxlength="80"
                               value="<?php echo nl2br(stripslashes($member_email)) ?>">
                    </div>
                </div>
                
                <?php if (!empty($member_img)) : ?>
                    <div class="form-row column">
                        <label>Photo actuelle</label>
                        <div class='actu-img-upload'><img src='../<?php echo $member_img; ?>'/></div>
                    </div>
                <?php endif; ?>
                
                
                <div class="form-row column">
                    <label>Mettre a jour la photo</label>
                    <ul class="file-list">
                        <li class="file-list-element">
                            <div class="dashboard-file-box">
                                <input type="file" name="f_ppl_img" id="f_ppl_img" class="inputfile"/>
                                <label for="f_ppl_img"
                                       class="upload-file-btn"><span>Mettre à jour la photo</span></label>
                            </div>
                            <script src="/js/custom-file-input.js"></script>
                        </li>
                    </ul>
                    
                    <h6>Attention les dimensions de l'image ne devraient pas dépasser 1200x1200 px</h6>
                    <h6>Pensez également à réduire a taille de votre fichier pour améliorer les performances de votre
                        site.</h6>
                </div>
            
            </div>
            
            <div class="d-form-cta">
                <div class="btn-primary small btn-revert icon mobile-icon-only"><span>Effacer</span></div>
                <div class="btn-primary small btn-confirm icon mobile-icon-only"><span>Mettre à jour</span></div>
            </div>
        </form>
    
    </div>

</div>