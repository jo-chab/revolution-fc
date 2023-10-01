<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Gérer les terrains</h4>
    </div>
    
    <div class="dashboard-content">
        
        
        <div class="btn-primary small cta-add icon mobile-icon-only i-more js-content-add">Ajouter un terrain</div>
        
        <div class="content-add">
            
            <form method="post" action="action_field_add" enctype="multipart/form-data">
                <div class="d-form-wrapper">
                    
                    <div class="grid-layout-2">
                        <div class="form-row column">
                            <label>Ville / Arrondissement</label>
                            <div class="select-dropdown">
                                <select name="ld_city" required>
                                    <option value="">Sélectionner un choix</option>
                                    <?php
                                        $stmt = $db->prepare("SELECT * FROM TERRAINS_cities order by id_city ASC");
                                        $stmt->execute();
                                        
                                        while ($curseur = $stmt->fetch()) {
                                            extract($curseur);
                                            
                                            $city = nl2br(stripslashes($city_name));
                                            echo "<option value=$id_city>$city</option>";
                                        }
                                    ?>
                                </select>
                            </div>
                        </div>
                        <div class="form-row column">
                            <label>Type de terrain</label>
                            <div class="select-dropdown">
                                <select name="ld_type" required>
                                    <option value="">Sélectionner un choix</option>
                                    <?php
                                        $stmt = $db->prepare("SELECT * FROM TERRAINS_type order by id_genre_terrain ASC");
                                        $stmt->execute();
                                        
                                        while ($curseur = $stmt->fetch()) {
                                            extract($curseur);
                                            
                                            $type = nl2br(stripslashes($genre_terrain));
                                            echo "<option value=$id_genre_terrain>$type</option>";
                                        }
                                    ?>
                                </select>
                            </div>
                        </div>
                    </div>
                    
                    <div class="grid-layout-2">
                        <div class="form-row column">
                            <label>Nom du terrrain (max 80 caract&egrave;res) :</label>
                            <input id="field_name" name="zt_name" type="text" maxlength="80" required>
                        </div>
<!--                        <div class="form-row column">-->
<!--                            <label>Description - optionnel (max 60 caract&egrave;res) :</label>-->
<!--                            <input id="field_desc" name="zt_desc" type="text" maxlength="60" required>-->
<!--                        </div>-->
                    </div>
                    
                    <div class="grid-layout-2">
                        <div class="form-row column">
                            <label>Lien Google Maps:</label>
                            <input id="field_map" name="zt_map" type="text" maxlength="256" required>
                        </div>
                        <div class="form-row column">
                            <label>Adresse:</label>
                            <textarea class="small" id="ta_address" name="ta_address" required></textarea>
                        </div>
                    </div>
                    
                    <div class="d-form-cta">
                        <div class="btn-primary small btn-confirm icon mobile-icon-only"><span>Ajouter</span></div>
                    </div>
                </div>
            </form>
        
        </div>
        
        <ul class="dashboard-list">
            <?php
                
                $sql1 = $db->prepare('select * from TERRAINS order by id_field ASC');
                $sql1->execute();
                
                $results = $sql1->fetchAll(PDO::FETCH_ASSOC);
                foreach ($results as $result) {
                    $id_field = $result['id_field'];
                    $name = nl2br(stripslashes($result['field_name']));
                    $actif = $result['actif'];
                    if ($actif == 1) {
                        $texte_bouton = "Désactiver";
                        $btnClass = "btn-disable";
                    } else {
                        $texte_bouton = "Activer";
                        $btnClass = "btn-activate";
                    }
                    
                    echo "<li class='dashboard-list-elements'>
                                    <div class='element-title'>
                                        $name
                                    </div>
                                    <div class='list-cta'>
                                        <div>
                                            <form action='action_field_disable' method='post'>
                                                <input type='hidden' name='element' value='$id_field'>
                                                <div class='btn-primary $btnClass small icon mobile-icon-only'><span>$texte_bouton</span></div>
                                            </form>
                                        </div>
                                        <div>
                                            <form action='?p=62' method='post'>
                                                <input type='hidden' name='element' value='$id_field'>
                                                <div class='btn-primary btn-update small icon mobile-icon-only'><span>Modifier</span></div>
                                            </form>
                                        </div>	
                                    </div>	
                                </li>";
                }
            ?>
        </ul>
    
    </div>

</div>