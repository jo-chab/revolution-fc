<?php
    
    $element = $_POST['element'];
    unset($_GET);
    
    $stmt = $db->prepare("SELECT * FROM EVENTS WHERE id_event = ? ");
    $stmt->execute([$element]);
    
    while ($curseur1 = $stmt->fetch())
    {
        extract($curseur1);
        
        $title = nl2br(stripslashes($event_name));
        $date = $event_date;
        $date_end = $event_date_end;
        $start = $event_start_time;
        $end = $event_end_time;
    }
    
    
    $supprElement = 1;
    $actionForm = "action_events_delete";
    $supprText = 'Supprimer définitivement?';

?>

<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Modifier <?php echo $title ?></h4>
    </div>
    
    <div class="dashboard-content">
        
        <form method="post" action="action_events_update" enctype="multipart/form-data">
            <div class="d-form-wrapper">
                
                <input name="element" type="hidden" value="<?php echo $element ?>">
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <div class="select-dropdown">
                            <label>Lieu</label>
                            <select name="ld_city" required>
                                <?php
                                    $stmt4 = $db->prepare("SELECT * FROM TERRAINS order by id_field ASC");
                                    $stmt4->execute();
                                    
                                    while ($curseur4 = $stmt4->fetch()) {
                                        extract($curseur4);
                                        if ($id_field == $event_venue) {
                                            $selected = "selected";
                                        } else {
                                            $selected = "";
                                        }
                                        $field = nl2br(stripslashes($field_name));
                                        echo "<option value=$id_field $selected>$field</option>";
                                    }
                                ?>
                            </select>
                        </div>
                    </div>
                </div>
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Nom de l'évènement (max : 80 caractères)</label>
                        <input id="zt_name" name="zt_name" type="text" maxlength="80" value="<?php echo $title ?>" required>
                    </div>
                </div>
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Date de l'évènement (début)</label>
                        <input id="zt_date" name="zt_date" type="date" value="<?php echo $date ?>" required>
                    </div>
                    <div class="form-row column">
                        <label>Date de fin de l'évènement (non obligatoire!)</label>
                        <input id="zt_date_end" name="zt_date_end" type="date" value="<?php echo $date_end ?>">
                    </div>
                </div>
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Heure de début</label>
                        <input id="zt_start" name="zt_start" type="time" value="<?php echo $start ?>" required>
                    </div>
                    <div class="form-row column">
                        <label>Heure de fin</label>
                        <input id="zt_end" name="zt_end" type="time" value="<?php echo $end ?>">
                    </div>
                </div>
            
            </div>
            <div class="d-form-cta">
                <div class="btn-primary btn-revert small icon mobile-icon-only"><span>Effacer les changements</span></div>
                <div class="btn-primary btn-confirm small icon mobile-icon-only"><span>Mettre à jour</span></div>
            </div>
        
        </form>
    
    </div>
</div>