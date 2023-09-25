<?php
    $categoryvoulu = $_POST['num_category'];
    $tournoivoulu = $_POST['num_tournoi'];
    unset($_POST);

    $sql1 = $db->prepare("SELECT * FROM TOURNAMENT_CATEGORIES WHERE id_t_category = ? ");
    $sql1->execute([$categoryvoulu]);

    while ($curseur1 = $sql1->fetch())
    {
        extract($curseur1);

        $soccer=nl2br(stripslashes($t_category_type));
        $category=nl2br(stripslashes($t_category_age));
        $fee=nl2br(stripslashes($t_category_fee));
        $link=nl2br(stripslashes($t_category_link));

    }
?>

<div class="dashboard-main">
    <div class="dashboard-title">
        <h4 class="white"><?php echo $category.' / '.$soccer ?></h4>
    </div>

    <div class="dashboard-content">

        <form method="post" action="action_tournoi_category_update.php" enctype="multipart/form-data">
            <div class="d-form-wrapper">

                <input name="num_category" type="hidden" value="<?php echo $categoryvoulu ?>">
                <input name="num_tournoi" type="hidden" value="<?php echo $tournoivoulu ?>">

                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Categorie d'age :</label>
                        <input id="t_category" name="zt_category" type="text" maxlength="256" value="<?php echo $category ?>" required>
                    </div>
                    <div class="form-row column">
                        <label>Type de soccer (7, 9, 11)</label>
                        <input id="t_soccer" name="zt_soccer" type="text" maxlength="30" value="<?php echo $soccer ?>" required>
                    </div>
                </div>
                <div class="grid-layout-2">
                    <div class="form-row column">
                        <label>Cout d'inscription</label>
                        <input id="t_fee" name="zt_fee" type="text" maxlength="30" value="<?php echo $fee ?>" required>
                    </div>
                    <div class="form-row column">
                        <label>Lien d'inscription :</label>
                        <input id="t_link" name="zt_link" type="text" maxlength="256" value="<?php echo $link ?>" required>
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