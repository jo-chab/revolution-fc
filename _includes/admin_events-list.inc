
<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Gérer les évènements</h4>
    </div>
    
    <div class="dashboard-content">
        
        <a class="btn-primary btn-add small icon i-more mobile-icon-only" href="?p=64"><span>Ajouter un évènement</span></a>
        
        <ul class="dashboard-list">
            <?php
                
                $sql1 = $db->prepare("SELECT * FROM EVENTS order by event_date DESC");
                $sql1->execute();
                $results = $sql1->fetchAll(PDO::FETCH_ASSOC);
                
                foreach ($results as $result) {
                    $event = $result['id_event'];
                    $name = nl2br(stripslashes($result['event_name']));
                    $actif=$result['is_actif'];
                    if ($actif==1)
                    {
                        $update="Désactiver";
                        $btnClass="btn-disable";
                    }
                    else
                    {
                        $update="Activer";
                        $btnClass="btn-activate";
                    }
                    
                    echo "<li class='dashboard-list-elements'>
                            <div class='element-title'>
                                $name
                            </div>
                            <div class='list-cta'>
                                <form action='action_events_disable' method='post'>
                                    <input type='hidden' name='element' value='$event'>
                                    <div class='btn-primary $btnClass small icon mobile-icon-only'><span>$update</span></div>
                                </form>
                                <form action='?p=65' method='post'>
                                    <input type='hidden' name='element' value='$event'>
                                    <div class='btn-primary btn-update small icon mobile-icon-only'><span>Modifier</span></div>
                                </form>
                            </div>
                        </li>";
                }
            ?>
        </ul>
    
    </div>
</div>



