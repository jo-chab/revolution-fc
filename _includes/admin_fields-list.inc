
        <div class="dashboard-main">
            <div class="dashboard-title">
                <h4 class="white">Gérer les terrains</h4>
            </div>

            <div class="dashboard-content">

                <ul class="dashboard-list">
                    <?php

                    $sql1 = $db->prepare('select * from TERRAINS order by id_terrain ASC');
                    $sql1->execute();

                    $results = $sql1->fetchAll(PDO::FETCH_ASSOC);
                    foreach($results as $result)
                    {
                        $id_terrain=$result['id_terrain'];
                        $name=nl2br(stripslashes($result['nom']));
//                        $address1=nl2br(stripslashes($result['adresse_1']));
//                        $address2=nl2br(stripslashes($result['adresse_2']));
//                        $mapLink=nl2br(stripslashes($result['google_maps']));
                        $actif=$result['actif'];
                        if ($actif==1)
                        {
                            $texte_bouton="Désactiver";
                            $class="";
                        }
                        else
                        {
                            $texte_bouton="Activer";
                            $class="is-inactive";
                        }

                        echo "<li class='dashboard-list-elements'>
                                    <div class='element-title'>
                                        $name
                                    </div>
                                    <div class='list-cta'>
                                        <div>
                                            <form action='action_field_update.php' method='post'>
                                                <input type='hidden' name='change' value='$id_terrain'>
                                                <input type='submit' class='cta-activate $class' value='$texte_bouton' />
                                            </form>
                                        </div>
                                        <div>
                                            <form action='index.php?p=62&id_field=$id_terrain' method='post'>
                                                <input type='hidden' name='modif' value='$id_terrain'>
                                                <input type='submit' class='cta-update' value='Modifier' />
                                            </form>
                                        </div>	
                                    </div>	
                                </li>";
                    }
                    ?>
                </ul>

                <div class="btn-primary cta-add icon i-more js-content-add">Ajouter un terrain</div>

                <div class="dashboard-content content-add">

                    <form method="post" action="action_field_add" enctype="multipart/form-data">
                        <div class="d-form-wrapper">

                            <div class="flex-layout-2">
                                <div>
                                    <label>Nom du terrrain (max 80 caract&egrave;res) :</label>
                                    <input id="tournament_name" name="zt_name" type="text" maxlength="80" required>
                                </div>
                                <div>
                                    <label>Texte introduction (max 256 caract&egrave;res) :</label>
                                    <input id="tournament_intro" name="zt_intro" type="text" maxlength="30" required>
                                </div>
                            </div>

                        </div>
                        <div class="d-form-cta">
                            <input type="submit" class="dashboard-btn-confirm" id="confirm-add-news" value="Ajouter le tournoi" />
                        </div>
                    </form>

                </div>

            </div>

        </div>