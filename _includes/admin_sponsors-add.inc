<div class="dashboard-main">
    
    <div class="dashboard-title">
        <h4 class="white">Ajouter un commanditaire</h4>
    </div>
    
    <div class="dashboard-content">
        <form method="post" action="action_sponsors_add.php" enctype="multipart/form-data">
            <div class="d-form-wrapper">
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Nom du commanditaire</label>
                        <input id="" name="zt_nom" type="text" value="" maxlength="64">
                    </div>
                    <div class="form-row column">
                        <label>Lien du site internet</label>
                        <input id="" name="zt_site" type="text" value="">
                    </div>
                </div>
                
                
                <div class="grid-layout-3">
                    <div class="form-row column">
                        <label>Commanditaire principal du club?</label>
                        <div class="select-dropdown">
                            <select name="ld_club" required>
                                <option value='1'>Oui</option>
                                <option value='0'>Non</option>
                            </select>
                        </div>
                    </div>
                    <div class="form-row column">
                        <label>Commanditaire pour tournoi &eacute;t&eacute;?</label>
                        <div class="select-dropdown">
                            <select name="ld_tournoi_summer" required>
                                <option value='1'>Oui</option>
                                <option value='0'>Non</option>
                            </select>
                        </div>
                    </div>
                    <div class="form-row column">
                        <label>Commanditaire pour tournoi hiver?</label>
                        <div class="select-dropdown">
                            <select name="ld_tournoi_winter" required>
                                <option value='1'>Oui</option>
                                <option value='0'>Non</option>
                            </select>
                        </div>
                    </div>
                </div>
                
                <div class="form-row column">
                    <label>Télécharger l'image du logo</label>
                    
                    <ul class="file-list">
                        <li class="file-list-element">
                            <div class="dashboard-file-box">
                                <input type="file" name="f_logo_img" id="f_logo_img" class="inputfile" />
                                <label for="f_logo_img" class="upload-file-btn"><span>Télécharger le logo</span></label>
                            </div>
                            <script src="/js/custom-file-input.js"></script>
                        </li>
                    </ul>
                </div>
            
            </div>
            
            <div class="d-form-cta">
                <div class="btn-primary btn-revert small icon mobile-icon-only"><span>Effacer</span></div>
                <div class="btn-primary btn-confirm small icon mobile-icon-only"><span>Enregistrer</span></div>
            </div>
        </form>
    
    </div>
</div>