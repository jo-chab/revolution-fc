<?php
    if(isset($_GET['type']))
    {
        $value=$_GET['type'];
        if ($value==0)
        {
            $value=0;
        }
        elseif ($value!=0)
        {
            $value=$_GET['type'];
        }
    }
    else {
        $value = 0;
    }

?>

        <div class="dashboard-main">
            <div class="dashboard-title">
                <h4 class="white">Gérer les commanditaires</h4>
            </div>

            <div class="dashboard-content">
                <a class="btn-primary small cta-add icon i-more" href="index.php?p=90">Ajouter un commanditaire</a>
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <div class="select-dropdown">
                            <label>Selectionner le type</label>
                            <select name="type" id="ld_type"  onchange="filterSponsors();">
                                <?php
                                    $options = [
                                        0 => 'Tous',
                                        1 => 'Sponsors Club',
                                        2 => 'Sponsors Tournoi été',
                                        3 => 'Sponsors Tournoi hiver'
                                    ];
                                    
                                    foreach ($options as $optionValue => $optionLabel) {
                                        $selected = ($value == $optionValue) ? 'selected' : '';
                                        echo "<option value='$optionValue' $selected>$optionLabel</option>";
                                    }
                                ?>
                            
                            
                            </select>
                        </div>
                    </div>
                </div>

                <ul class="dashboard-list">
                    <?php

                    if ($value==0)
                    {
                        $sql1 = $db->prepare('select * from SPONSORS order by id_sponsors DESC');
                        $sql1->execute();
                    }
                    elseif ($value==1)
                    {
                        $sql1 = $db->prepare('select * from SPONSORS where is_club = 1 order by id_sponsors DESC');
                        $sql1->execute();
                    }
                    elseif ($value==2)
                    {
                        $sql1 = $db->prepare('select * from SPONSORS where is_tournament_summer = 1 order by id_sponsors DESC');
                        $sql1->execute();
                    }
                    elseif ($value==3)
                    {
                        $sql1 = $db->prepare('select * from SPONSORS where is_tournament_winter = 1 order by id_sponsors DESC');
                        $sql1->execute();
                    }

                    $cpt1=0;
                    $results = $sql1->fetchAll(PDO::FETCH_ASSOC);
                    foreach($results as $result)
                    {
                        $id_sponsors=$result['id_sponsors'];
                        $nom=nl2br(stripslashes($result['name_sponsors']));
                        $logo=nl2br(stripslashes($result['logo_sponsors']));
                        $club=$result['is_club'];
                        $summer=$result['is_tournament_summer'];
                        $winter=$result['is_tournament_winter'];
                        $actif=$result['actif'];
                        $cpt1++;

                        if ($club==1)
                        {
                            $dataType="sponsor-club";
                            $class="sponsors-club";
                        }
                        elseif ($summer==1)
                        {
                            $dataType="sponsor-summer";
                            $class="sponsor-summer";
                        }
                        elseif ($winter==1)
                        {
                            $dataType="sponsor-winter";
                            $class="sponsor-winter";
                        }
                        else
                        {
                            $dataType="no-data";
                            $class="";
                        }

                        echo "<li class='dashboard-list-elements layout-delete'>
                                    <div class='list-cta'>
                                        <form action='action_sponsors_delete' method='post'>
                                            <input type='hidden' name='element' value='$id_sponsors'>
                                            <div class='btn-tertiary btn-text small btn-delete icon mobile-icon-only'></div>
                                        </form>
                                    </div>
                                    <div class='element-title content-id'>
                                        <span class='logo-mini'><img src='..$logo' alt='$nom' /></span> $nom
                                    </div>
                                    <div class='list-cta content-btn'>
                                        <form action='?p=92' method='post'>
                                            <input type='hidden' name='element' value='$id_sponsors'>
                                            <div class='btn-primary btn-update small icon mobile-icon-only'><span>Modifier</span></div>
                                        </form>
                                    </div>
                                </li>";
                    }
                    ?>
                </ul>

            </div>
        </div>



        <script>

            function filterSponsors() {
                var value = document.getElementById('ld_type').value;
                console.log(value);
                document.location.href = 'index.php?p=91&type=' + value;
            }

        </script>