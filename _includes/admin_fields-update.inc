<?php
$fieldSelected = $_GET['id_field'];
unset($_GET);

$sql1 = $db->prepare("SELECT * FROM TERRAINS WHERE id_terrain = '$fieldSelected'");
$sql1->execute();

while ($curseur1 = $sql1->fetch())
{
    extract($curseur1);

    $name=nl2br(stripslashes($nom));
    $address1=nl2br(stripslashes($adresse_1));
    $address2=nl2br(stripslashes($adresse_2));
    $map=nl2br(stripslashes($google_maps));
    $season=nl2br(stripslashes($data_season));
}
?>

        <div class="dashboard-main">
            <div class="dashboard-title">
                <h4 class="white">Modifier <?php echo $name ?></h4>
            </div>

            <div class="dashboard-content">

                <form method="post" action="action_tournoi_modif.php" enctype="multipart/form-data">
                    <div class="d-form-wrapper">

                        <input name="num_tournoi" type="hidden" value="<?php echo $fieldSelected ?>">

                        <div class="flex-layout-2">
                            <div>
                                <label>Nom du terrain (max : 80 caractères)</label>
                                <input id="t_name" name="zt_name" type="text" maxlength="80" value="<?php echo $name ?>" required>
                            </div>
                            <div>
                                <label>Lien google maps</label>
                                <input id="t_desc" name="zt_desc" type="text" maxlength="256" value="<?php echo $map ?>">
                            </div>
                        </div>
                        <div class="flex-layout-2">
                            <div>
                                <label>numero et rue</label>
                                <input id="t_name" name="zt_name" type="text" maxlength="80" value="<?php echo $address1 ?>" required>
                            </div>
                            <div>
                                <label>Ville et code postal</label>
                                <input id="t_desc" name="zt_desc" type="text" maxlength="256" value="<?php echo $address2 ?>">
                            </div>
                        </div>

                        <div class="flex-layout-3">
                            <div>
                                <label>Type de saison</label>
                                <div class="select-dropdown">
                                    <select name="ld_season" required>
                                        <?php
//                                            if($id_actu_section==$id_section){
//                                                $selected_section = "selected";
//                                            }
//                                            else{
//                                                $selected_section = "";
//                                            }
//                                            echo "<option value=$id_actu_section $selected_section>$section</option>";
                                        ?>
                                    </select>
                                </div>
                            </div>
                            <div>
                                <label>Type de terrain</label>
                                <div class="select-dropdown">
                                    <select name="ld_type" required>
                                        <?php
                                        $stmt3 = $db->prepare("SELECT * FROM TERRAINS_type order by id_genre_terrain ASC");
                                        $stmt3->execute();

                                        while ($curseur3 = $stmt3->fetch())
                                        {
                                            extract($curseur3);
                                            if($id_genre_terrain==$data_genre){
                                                $selected_type = "selected";
                                            }
                                            else{
                                                $selected_type = "";
                                            }
                                            $type=nl2br(stripslashes($genre_terrain));
                                            echo "<option value=$id_genre_terrain $selected_type>$type</option>";
                                        }
                                        ?>
                                    </select>
                                </div>
                            </div>
                            <div>
                                <label>Ville</label>
                                <div class="select-dropdown">
                                    <select name="ld_city" required>
                                        <?php
                                        $stmt4 = $db->prepare("SELECT * FROM TERRAINS_cities order by id_city ASC");
                                        $stmt4->execute();

                                        while ($curseur4 = $stmt4->fetch())
                                        {
                                            extract($curseur4);
                                            if($id_city==$data_city){
                                                $selected_city = "selected";
                                            }
                                            else{
                                                $selected_city = "";
                                            }
                                            $city=nl2br(stripslashes($city_name));
                                            echo "<option value=$id_city $selected_city>$city</option>";
                                        }
                                        ?>
                                    </select>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="d-form-cta">
                        <input type="submit" class="dashboard-btn-confirm" id="confirm-add-news" value="Valider les modifications" />
                        <input type="reset" class="dashboard-btn-cancel" id="cancel-add-news" value="Effacer les modifications" />
                    </div>

                </form>

            </div>
        </div>