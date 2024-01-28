
        <div class="dashboard-main">
            <div class="dashboard-title">
                <h4 class="white">Ajouter un evenement</h4>
            </div>

            <div class="dashboard-content">

                <form method="post" action="action_events_add" enctype="multipart/form-data">
                    <div class="d-form-wrapper">


                        <div class="grid-layout-2">
                            <div class="form-row column">
                                <div class="select-dropdown">
                                    <label>Choisir le terrain de l'evenement</label>
                                    <select name="ld_city" required>
                                        <option value="">Sélectionner le lieu</option>
                                        <?php
                                        $stmt4 = $db->prepare("SELECT * FROM TERRAINS order by id_field ASC");
                                        $stmt4->execute();

                                        while ($curseur4 = $stmt4->fetch())
                                        {
                                            extract($curseur4);

                                            $field=nl2br(stripslashes($field_name));
                                            echo "<option value=id_field>$field</option>";
                                        }
                                        ?>
                                    </select>
                                </div>
                            </div>
                        </div>

                        <div class="grid-layout-2">
                            <div class="form-row column">
                                <label>Nom de l'évènement (max : 80 caractères)</label>
                                <input id="zt_name" name="zt_name" type="text" maxlength="80" value="" required>
                            </div>
                        </div>
                        <div class="grid-layout-2">
                            <div class="form-row column">
                                <label>Date de l'évènement (début)</label>
                                <input id="zt_date" name="zt_date" type="date" value="" required>
                            </div>
                            <div class="form-row column">
                                <label>Date de fin de l'évènement (non obligatoire!)</label>
                                <input id="zt_date_end" name="zt_date_end" type="date" value="">
                            </div>
                            
                            <div class="form-row column">
                                <label>Heure de début</label>
                                <input id="zt_start" name="zt_start" type="time" value="" required>
                            </div>
                            <div class="form-row column">
                                <label>Heure de fin</label>
                                <input id="zt_end" name="zt_end" type="time" value="">
                            </div>
                        </div>

                    </div>
                    <div class="d-form-cta">
                        <div class="btn-primary btn-revert small icon mobile-icon-only"><span>Effacer</span></div>
                        <div class="btn-primary btn-confirm small icon mobile-icon-only"><span>Valider</span></div>
                    </div>

                </form>

            </div>
        </div>