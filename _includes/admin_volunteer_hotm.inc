<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Liste des benevoles du mois</h4>
    </div>
    
    <div class="dashboard-content">
        
        <div class="w-tooltips">
            <i class="fa-light fa-circle-question"></i> Attention: il ne peut pas y avoir deux personnes sur le même mois et année !
        </div>
        
        <div class="d-form-cta header">
            <div class="btn-primary btn-add small icon mobile-icon-only i-more js-content-add">Ajouter le benevole du mois</div>
        </div>
        
        <div class="dashboard-content content-add">
            
            <form method="post" action="action_volunteer_hotm_add" enctype="multipart/form-data">
                <div class="d-form-wrapper">
                    
                    <div class="grid-layout-2">
                        <div class="form-row column">
                            <label>Entrer l'année</label>
                            <input id="d_year" name="d_year" type="number" value="<?php echo date('Y'); ?>" required>
                        </div>
                        
                        <div class="form-row column">
                            <label>Choisir le mois</label>
                            <select id="d_month" name="d_month" required>
                                <option value="1">Janvier</option>
                                <option value="2">Février</option>
                                <option value="3">Mars</option>
                                <option value="4">Avril</option>
                                <option value="5">Mai</option>
                                <option value="6">Juin</option>
                                <option value="7">Juillet</option>
                                <option value="8">Août</option>
                                <option value="9">Septembre</option>
                                <option value="10">Octobre</option>
                                <option value="11">Novembre</option>
                                <option value="12">Décembre</option>
                            </select>
                        </div>
                    
                    </div>
                    
                    <div class="grid-layout-2">
                        <div class="form-row column">
                            <label>Nom du benevoles (max : 120 caractères)</label>
                            <input id="zt_name" name="zt_name" type="text" maxlength="120" value=""
                                   required>
                        </div>
                        <div class="form-row column">
                            <label>Fonction du benevoles (max : 80 caractères)</label>
                            <input id="zt_pos" name="zt_pos" type="text" maxlength="80" value=""
                                   required>
                        </div>
                    </div>
                    
                    <div class="form-row column">
                        <label>Description du benevoles (max : 260 caractères)</label>
                        <input id="zt_desc" name="zt_desc" type="text" maxlength="260" value=""
                               required>
                    </div>
                    
                    <div class="form-row column">
                        <label>Citation du benevole :</label>
                        <textarea id="ta_quote" name="ta_quote" required></textarea>
                    </div>
                
                </div>
                <div class="d-form-cta">
                    <div class="btn-primary small btn-confirm icon mobile-icon-only"><span>Enregister</span></div>
                </div>
            
            </form>
            
        </div>
        
        <ul class="dashboard-list">
            <?php
                
                $sql1 = $db->prepare("SELECT * FROM VOLUNTEER_hotm ORDER BY hotm_year ASC, hotm_month ASC");
                $sql1->execute();
                
                $results = $sql1->fetchAll(PDO::FETCH_ASSOC);
                foreach ($results as $result) {
                    $id = $result['id_hotm'];
                    $name = nl2br(stripslashes($result['hotm_name']));
                    $desc = nl2br(stripslashes($result['hotm_desc']));
                    $pos = nl2br(stripslashes($result['hotm_pos']));
                    $quote = nl2br(stripslashes($result['hotm_quote']));
                    
                    $year = $result['hotm_year'];
                    $monthNumber = $result['hotm_month'];
                    setlocale(LC_TIME, 'fr_FR');
                    $monthName = utf8_encode(strftime('%B', mktime(0, 0, 0, $monthNumber, 1)));
                    
                    echo "
                                <li class='dashboard-list-elements layout-col-3'>
                                    <div class='list-cta content-icon'>
                                        <form action='action_volunteer_hotm_delete' method='post'>
                                            <input type='hidden' name='element' value='$id'>
                                            <div class='btn-tertiary btn-text small btn-delete icon mobile-icon-only'></div>
                                        </form>
                                    </div>
                                    <div class='element-title content-element'><span>$monthName $year</span> - $name</div>
                                    <div class='list-cta content-btn'>
                                        <div data-element='$id' class='btn-primary small btn-update icon js-content-update'><span>Modifier</span></div>
                                    </div>
                                    <div class='content-update content-update-$id'>
                                        <form method='post' action='action_volunteer_hotm_update' enctype='multipart/form-data'>
                                            <input name='element' type='hidden' value='$id'>
                    
                                            <div class='grid-layout-2'>
                                                <div class='form-row column'>
                                                    <label>Nom du benevoles (max : 120 caractères)</label>
                                                    <input id='zt_name' name='zt_name' type='text' maxlength='120' value='$name'
                                                        required>
                                                </div>
                                                <div class='form-row column'>
                                                    <label>Fonction du benevoles (max : 80 caractères)</label>
                                                    <input id='zt_pos' name='zt_pos' type='text' maxlength='80' value='$pos'
                                                           required>
                                                </div>
                                            </div>
                                            
                                            <div class='form-row column'>
                                                <label>Description du benevoles (max : 260 caractères)</label>
                                                <input id='zt_desc' name='zt_desc' type='text' maxlength='260' value='$desc'
                                                       required>
                                            </div>
                                            
                                            <div class='form-row column'>
                                                <label>Citation du benevole :</label>
                                                <textarea id='ta_quote' name='ta_quote' required>$quote</textarea>
                                            </div>
                                            <div class='d-form-cta'>
                                                <div class='btn-tertiary small btn-cancel icon mobile-icon-only js-cancel-update'><span>Annuler</span></div>
                                                <div class='btn-primary small btn-confirm icon mobile-icon-only'><span>Mettre à jour</span></div>
                                            </div>
                                        </form>
                                    </div>
                                </li>
                                ";
                }
            ?>
        </ul>
    
    </div>
</div>