<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Gérer les tournois</h4>
    </div>
    
    <div class="dashboard-content">
        
        <div class="btn-primary cta-add js-content-add">Ajouter un tournoi</div>
        
        
        <div class="dashboard-content content-add" style="margin-top: 3rem;">
            
            <form method="post" action="action_tournament_add" enctype="multipart/form-data">
                <div class="d-form-wrapper">
                    
                    <div class="grid-layout-2">
                        <div class="form-row column">
                            <label>Nom du tournoi (max 80 caract&egrave;res) :</label>
                            <input id="tournament_name" name="zt_name" type="text" maxlength="80" required>
                        </div>
                    </div>
                    
                    <div class="form-row column">
                        <label>Texte introduction (max 256 caract&egrave;res) :</label>
                        <input id="tournament_intro" name="zt_intro" type="text" maxlength="30" required>
                    </div>
                    
                    <div class="form-row column">
                        <label>Texte :</label>
                        <?php include("text-panel-tournoi.inc"); ?>
                        <textarea id="zt_text" name="ta_tournoi" required></textarea>
                    </div>
                    
                    
                    <ul class="file-list">
                        <li class="file-list-element">
                            <div class="dashboard-file-box">
                                <input type="file" name="f_photo_tournoi" id="f_photo_tournoi" class="inputfile" />
                                <label for="f_photo_tournoi" class="upload-file-btn"><span>Télécharger l'image</span></label>
                            </div>
                            <script src="/js/custom-file-input.js"></script>
                        </li>
                    </ul>
                    <h6>Attention les dimensions de l'image ne doivent pas dépasser 1200x800
                        px</h6>
                    <h6>Pensez également à réduire a taille de votre fichier pour améliorer
                        les performances de votre site.</h6>
                
                
                </div>
                <div class="d-form-cta">
                    <div class="btn-primary btn-revert icon mobile-icon-only"><span>Effacer</span></div>
                    <div class="btn-primary btn-validate icon mobile-icon-only"><span>Valider</span></div>
                </div>
            </form>
        
        </div>
        
        <ul class="dashboard-list">
            <?php
                
                $sql1 = $db->prepare('select * from TOURNAMENT order by id_tournament ASC');
                $sql1->execute();
                
                $results = $sql1->fetchAll(PDO::FETCH_ASSOC);
                foreach ($results as $result) {
                    $id_tournament = $result['id_tournament'];
                    $name = nl2br(stripslashes($result['tournament_name']));
                    $actif = $result['actif'];
                    if ($actif==1)
                    {
                        $texte_bouton="Désactiver";
                        $btnClass="btn-disable";
                    }
                    else
                    {
                        $texte_bouton="Activer";
                        $btnClass="btn-activate";
                    }
                    
                    echo "
                                <li class='dashboard-list-elements'>
                                    <div class='element-title'>$name</div>
                                    <div class='list-cta'>
                                        <div>
                                            <form action='action_tournament_disable.php' method='post'>
                                                <input type='hidden' name='element' value='$id_tournament'>
                                                <div class='btn-primary $btnClass icon mobile-icon-only'><span>$texte_bouton</span></div>
                                            </form>
                                        </div>
                                        <div>
                                            <form action='index.php?p=82&t=$id_tournament' method='post'>
                                                <div class='btn-primary btn-update icon mobile-icon-only'><span>Modifier</span></div>
                                            </form>
                                        </div>
                                    </div>
                                </li>
                                ";
                }
            ?>
        </ul>
    
    </div>

</div>