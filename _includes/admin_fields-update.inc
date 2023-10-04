<?php
    $element = $_POST['element'];
    unset($_POST);
    
    $sql1 = $db->prepare("SELECT * FROM TERRAINS WHERE id_field = '$element'");
    $sql1->execute();
    
    while ($curseur1 = $sql1->fetch()) {
        extract($curseur1);
        
        $name = nl2br(stripslashes($field_name));
        $address = nl2br(stripslashes($field_address));
        $address = str_replace('<br />', "", $address);
        $map = nl2br(stripslashes($field_map));
    }
    
    $supprElement = 1;
    $actionForm = "action_field_delete.php";
    $supprText = 'Supprimer le terrain';
?>

<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Modifier <?php echo $name ?></h4>
    </div>
    
    <div class="dashboard-content">
        
        <form method="post" action="action_field_update" enctype="multipart/form-data">
            <div class="d-form-wrapper">
                
                <input name="element" type="hidden" value="<?php echo $element ?>">
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <div class="select-dropdown">
                            <label>Type de terrain</label>
                            <select name="ld_type" required>
                                <?php
                                    $stmt3 = $db->prepare("SELECT * FROM TERRAINS_type order by id_genre_terrain ASC");
                                    $stmt3->execute();
                                    
                                    while ($curseur3 = $stmt3->fetch()) {
                                        extract($curseur3);
                                        if ($id_genre_terrain == $data_genre) {
                                            $selected_type = "selected";
                                        } else {
                                            $selected_type = "";
                                        }
                                        $type = nl2br(stripslashes($genre_terrain));
                                        echo "<option value=$id_genre_terrain $selected_type>$type</option>";
                                    }
                                ?>
                            </select>
                        </div>
                    </div>
                    <div class="form-row column">
                        <div class="select-dropdown">
                            <label>Ville</label>
                            <select name="ld_city" required>
                                <?php
                                    $stmt4 = $db->prepare("SELECT * FROM TERRAINS_cities order by id_city ASC");
                                    $stmt4->execute();
                                    
                                    while ($curseur4 = $stmt4->fetch()) {
                                        extract($curseur4);
                                        if ($id_city == $data_city) {
                                            $selected_city = "selected";
                                        } else {
                                            $selected_city = "";
                                        }
                                        $city = nl2br(stripslashes($city_name));
                                        echo "<option value=$id_city $selected_city>$city</option>";
                                    }
                                ?>
                            </select>
                        </div>
                    </div>
                </div>
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Nom du terrain (max : 80 caractères)</label>
                        <input id="t_name" name="zt_name" type="text" maxlength="80" value="<?php echo $name ?>" required>
                    </div>
                </div>
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Lien Google Maps:</label>
                        <input id="field_map" name="zt_map" type="text" maxlength="256" value="<?php echo $map ?>" required>
                    </div>
                    <div class="form-row column">
                        <label>Adresse:</label>
                        <textarea class="small" id="ta_address" name="ta_address" required><?php echo $address ?></textarea>
                    </div>
                </div>
                
            </div>
            <div class="d-form-cta">
                <div class="btn-primary small btn-revert icon mobile-icon-only"><span>Effacer</span></div>
                <div class="btn-primary small btn-validate icon mobile-icon-only"><span>Mettre à jour</span></div>
            </div>
        
        </form>
    
    </div>
</div>