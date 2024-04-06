<?php
    $element = $_POST['element'];
    unset($_POST);
    
    $sql1 = $db->prepare("SELECT * FROM VOLUNTEER_hotm WHERE id_hotm = ?");
    $sql1->execute([$element]);
    
    while ($curseur1 = $sql1->fetch())
    {
        extract($curseur1);
    }
?>


<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Modifier <?php echo nl2br(stripslashes($hotm_name)) ?></h4>
    </div>
    
    <div class="dashboard-content">
        
            
            <form method="post" action="action_volunteer_hotm_update" enctype="multipart/form-data">
                <div class="d-form-wrapper">
                    
                    <input name="element" type="hidden" value="<?php echo $element ?>">
                    
                    <div class="grid-layout-2">
                        <div class="form-row column">
                            <label>Nom du benevoles (max : 120 caractères)</label>
                            <input id="zt_name" name="zt_name" type="text" maxlength="120" value="<?php echo nl2br(stripslashes($hotm_name)) ?>"
                                   required>
                        </div>
                        <div class="form-row column">
                            <label>Fonction du benevoles (max : 80 caractères)</label>
                            <input id="zt_pos" name="zt_pos" type="text" maxlength="80" value="<?php echo nl2br(stripslashes($hotm_pos)) ?>"
                                   required>
                        </div>
                    </div>
                    
                    <div class="form-row column">
                        <label>Description du benevoles (max : 260 caractères)</label>
                        <input id="zt_desc" name="zt_desc" type="text" maxlength="260" value="<?php echo nl2br(stripslashes($hotm_desc)) ?>"
                               required>
                    </div>
                    
                    <div class="form-row column">
                        <label>Citation du benevole :</label>
                        <textarea id="ta_quote" name="ta_quote" required><?php echo nl2br(stripslashes($hotm_quote)) ?></textarea>
                    </div>
                
                </div>
                <div class="d-form-cta">
                    <div class="btn-primary small btn-confirm icon mobile-icon-only"><span>Enregister</span></div>
                </div>
            
            </form>
        
    
    </div>
</div>