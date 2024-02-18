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
                <a class="btn-primary small btn-add icon i-more" href="index.php?p=90">Ajouter un commanditaire</a>

                <ul class="dashboard-list">
                    <?php
                    
                    $sql1 = $db->prepare('select * from SPONSORS order by name_sponsors ASC');
                    $sql1->execute();

                    $cpt1=0;
                    $results = $sql1->fetchAll(PDO::FETCH_ASSOC);
                    foreach($results as $result)
                    {
                        $id_sponsors=$result['id_sponsors'];
                        $nom=nl2br(stripslashes($result['name_sponsors']));
                        $logo=nl2br(stripslashes($result['logo_sponsors']));
                        $actif=$result['actif'];
                        $cpt1++;

                        echo "<li class='dashboard-list-elements layout-col-3'>
                                    <div class='list-cta content-icon'>
                                        <form action='action_sponsors_delete' method='post'>
                                            <input type='hidden' name='element' value='$id_sponsors'>
                                            <div class='btn-tertiary btn-text small btn-delete icon mobile-icon-only'></div>
                                        </form>
                                    </div>
                                    <div class='element-title content-element'>
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