

            <div class="dashboard-content content-add">

                <form method="post" action="action_tournoi_category_add" enctype="multipart/form-data">
                    <div class="d-form-wrapper">

                        <input name="num_tournoi" type="hidden" value="<?php echo $element ?>">

                        <div class="grid-layout-2">
                            <div class="form-row column">
                                <label>Categorie d'age*</label>
                                <input id="t_category" name="zt_category" type="text" maxlength="256" required>
                            </div>
                            <div class="form-row column">
                                <label>Type de soccer (7, 9, 11)*</label>
                                <input id="t_soccer" name="zt_soccer" type="text" maxlength="30" required>
                            </div>
                        </div>
                        <div class="grid-layout-2">
                            <div class="form-row column">
                                <label>Cout d'inscription*</label>
                                <input id="t_fee" name="zt_fee" type="text" maxlength="30" required>
                            </div>
                            <div class="form-row column">
                                <label>Lien d'inscription*</label>
                                <input id="t_link" name="zt_link" type="text" maxlength="256" required>
                            </div>
                        </div>
                        
                        <h6>* Les 4 champs doivent etre remplis, autrement, l'ajout de la cat&eacute;gorie ne fonctionnera pas</h6>

                    </div>
                    <div class="d-form-cta">
                        <div class="btn-primary btn-confirm small icon mobile-icon-only"><span>Ajouter cat&eacute;gorie</span></div>
                    </div>

                </form>

            </div>