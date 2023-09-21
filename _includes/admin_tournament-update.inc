<?php
    $element = $_GET['t'];
    unset($_GET);
    
    $sql1 = $db->prepare("SELECT * FROM TOURNAMENT WHERE id_tournament = ? ");
    $sql1->execute([$element]);
    
    while ($curseur1 = $sql1->fetch()) {
        extract($curseur1);
        
        $name = nl2br(stripslashes($tournament_name));
        $desc = nl2br(stripslashes($tournament_desc));
        $texte = nl2br(stripslashes($tournament_text));
        $texte = str_replace("<br /><br />", "", $texte);
        $texte = str_replace("<br />", "", $texte);
    }
    
    $supprElement = 1;
    $actionForm = "action_tournament_delete.php";
    $supprText = 'Supprimer le tournoi';
?>

<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Modifier <?php echo $name ?></h4>
    </div>
    
    <div class="dashboard-content">
        
        <form method="post" action="action_tournament_update" enctype="multipart/form-data">
            <div class="d-form-wrapper">
                
                <input name="element" type="hidden" value="<?php echo $element ?>">
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Nom du tournoi (max : 80 caractères)</label>
                        <input id="zt_name" name="zt_name" type="text" maxlength="80" value="<?php echo $name ?>"
                               required>
                    </div>
                </div>
                <div class="form-row column">
                    <label>Description (max : 256 caractères)</label>
                    <input id="zt_desc" name="zt_desc" type="text" maxlength="256" value="<?php echo $desc ?>">
                </div>
                
                <div class="form-row column">
                    <label>Texte :</label>
                    <?php include("text-panel-tournoi.inc"); ?>
                    <textarea id="ta_tournoi" name="ta_tournoi" required><?php echo $texte ?></textarea>
                </div>
                
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Photo actuelle</label>
                        <?php
                            echo "<div class='actu-img-upload'><img src='../$tournament_img' alt='$name' /></div>";
                        ?>
                    </div>
                    
                    <div>
                        <ul class="file-list">
                            <li class="file-list-element">
                                <div class="dashboard-file-box">
                                    <input type="file" name="f_photo_tournoi" id="f_photo_tournoi" class="inputfile"/>
                                    <label for="f_photo_tournoi"
                                           class="upload-file-btn"><span>Télécharger nouvelle image</span></label>
                                </div>
                                <script src="/js/custom-file-input.js"></script>
                            </li>
                        </ul>
                        <h6>Attention les dimensions de l'image ne doivent pas dépasser 1200x800
                            px</h6>
                        <h6>Pensez également à réduire a taille de votre fichier pour améliorer
                            les performances de votre site.</h6>
                    </div>
                </div>
            
            </div>
            <div class="d-form-cta">
                <div class="btn-primary btn-revert icon mobile-icon-only"><span>Effacer</span></div>
                <div class="btn-primary btn-validate icon mobile-icon-only"><span>Valider</span></div>
            </div>
        
        </form>
    
    </div>
</div>

<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white">Gérer les catégories pour <?php echo $name ?></h4>
    </div>
    
    <div class="dashboard-content">
        
        <ul class="dashboard-list">
            
            <?php
                
                $sql2 = $db->prepare('select * from TOURNAMENT_CATEGORIES where select_tournament = ? order by id_t_category ASC');
                $sql2->execute([$element]);
                
                $results2 = $sql2->fetchAll(PDO::FETCH_ASSOC);
                foreach ($results2 as $result) {
                    $id_category = $result['id_t_category'];
                    $soccer = nl2br(stripslashes($result['t_category_type']));
                    $category = nl2br(stripslashes($result['t_category_age']));
                    
                    echo "
            <li class='dashboard-list-elements layout-delete'>
                <div class='list-cta content-delete'>
                      <form action='action_tournoi_category_delete' method='post'>
                        <input type='hidden' name='num_category' value='$id_category'>
                        <input type='hidden' name='num_tournoi' value='$element'>
                        <div class='btn-secondary btn-delete icon mobile-icon-only'></div>
                    </form>
                </div>
                <div class='element-title'>$category – $soccer</div>
                <div class='list-cta content-btn'>
                    <form action='index.php?p=85' method='post'>
                        <input type='hidden' name='num_category' value='$id_category'>
                        <input type='hidden' name='num_tournoi' value='$element'>
                        <div class='btn-primary btn-update icon mobile-icon-only'><span>Modifier</span></div>
                    </form>
                </div>
            </li>
                                ";
                    
                }
            ?>
            
            <div class="btn-primary cta-add js-content-add"><a><i class="fa-regular fa-file-plus"></i> Ajouter une
                    categorie</a></div>
            
            <?php include("../_includes/admin_tournament_category-add.inc"); ?>
        
        </ul>
    
    </div>
</div>