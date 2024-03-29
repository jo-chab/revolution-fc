<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Gérer les membres de l'administration</h4>
    </div>
    
    
    <div class="dashboard-content">
        
        <div class="d-form-cta header">
            <div class="btn-primary small btn-add icon mobile-icon-only i-more js-content-add"><span>Ajouter un.e membre de l'administration</span></div>
        </div>
        
        <div class="dashboard-content content-add">
            
            <form method="post" action="action_ppl_admin_add" enctype="multipart/form-data">
                <div class="d-form-wrapper">
                    <h3>Ajouter un.e membre de l'administration</h3>
                    
                    <div class="grid-layout-2">
                        <div class="form-row column">
                            <label>Nom de la personne*</label>
                            <input id="zt_name" name="zt_name" type="text" maxlength="100" required>
                        </div>
                        <div class="form-row column">
                            <label>Texte descriptif (max 80 caract&egrave;res) :</label>
                            <input id="zt_desc" name="zt_desc" type="text" maxlength="80">
                        </div>
                    </div>
                    
                    <div class="grid-layout-2">
                        <div class="form-row column">
                            <label>Fonction (max 80 caract&egrave;res)*</label>
                            <input id="zt_function" name="zt_function" type="text" maxlength="80" required>
                        </div>
                        <div class="form-row column">
                            <label>Email associé à la personne :</label>
                            <input id="zt_email" name="zt_email" type="email" maxlength="80">
                        </div>
                    </div>
                    
                    <ul class="file-list">
                        <li class="file-list-element">
                            <div class="dashboard-file-box">
                                <input type="file" name="f_ppl_img" id="f_ppl_img" class="inputfile"/>
                                <label for="f_ppl_img" class="upload-file-btn"><span>Télécharger la photo</span></label>
                            </div>
                            <script src="/js/custom-file-input.js"></script>
                        </li>
                    </ul>
                    
                    <h6>Attention les dimensions de l'image ne devraient pas dépasser 1200x1200 px pour éviter de ralentir le site !</h6>
                    <h6>Pensez également à réduire a taille de votre fichier pour améliorer les performances de votre site, ou utiliser un fichier .SVG.</h6>
                
                
                </div>
                <div class="d-form-cta">
                    <div class="btn-primary small btn-confirm icon mobile-icon-only"><span>Enregistrer</span></div>
                </div>
            </form>
        
        </div>
        
        <ul class="dashboard-list">
            <?php
                $sql1 = $db->prepare('SELECT * from MEMBERS_ADMIN ORDER BY
                    CASE 
                        WHEN member_function = "Directeur Général" THEN 1
                        ELSE 2
                    END, member_function ASC');
                $sql1->execute();
                
                $results = $sql1->fetchAll(PDO::FETCH_ASSOC);
                foreach ($results as $result) {
                    $member = $result['id_member'];
                    $function = nl2br(stripslashes($result['member_function']));
                    $name = nl2br(stripslashes($result['member_name']));
                    
                    echo "
                    <li class='dashboard-list-elements layout-col-2'>
                        <div class='element-title content-element'><span>$function</span> – $name</div>
                        <div class='list-cta content-btn'>
                        ";
                    
                    // Check if member_function is "Administrateur" before displaying the delete form
                    if ($function !== "Directeur Général") {
                        echo "
                            <form action='action_ppl_admin_delete' method='post'>
                                <input type='hidden' name='element' value='$member'>
                                <div class='btn-primary small btn-delete icon mobile-icon-only validate-form'><span>Supprimer</span></div>
                            </form>
                            ";
                    }
                    
                    echo "
                            <form action='?p=24' method='post'>
                                <input type='hidden' name='element' value='$member'>
                                <div class='btn-primary small btn-update icon mobile-icon-only validate-form'><span>Modifier</span></div>
                            </form>
                        </div>	
                    </li>
                    ";
                }
            ?>
        </ul>
    
    </div>

</div>