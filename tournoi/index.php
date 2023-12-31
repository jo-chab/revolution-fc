<?php    include("../_includes/session_test.inc");    include("../_includes/_revolutionfc.inc");?><!doctype html><html><head><meta charset="UTF-8"><?php    $tournoi = $_GET['tournoi'];    $stmt = $db->prepare('select * from TOURNAMENT where id_tournament = ? ');    $stmt->execute([$tournoi]);    while ($curseur1 = $stmt->fetch()) {        extract($curseur1);        $name = $tournament_name;        $desc = nl2br(stripslashes($tournament_desc));        $photo = 'https://www.revolutionfc.ca/' . $tournament_img;        $texte = nl2br(stripslashes($tournament_text));        $texte = str_replace("<br /><br />", "", $texte);        $texte = str_replace("<br />", "", $texte);    }?><title><?php echo $name ?></title><?php    include("../_includes/head.inc");    echo "<body class='w-tournoi'>";    include("../_includes/header.inc");?><section class="p-tournament">    <article class="wrapper-text">        <h2 class="section-title"><?php echo $desc ?></h2>        <div class="tournament-img">            <img src="<?php echo $photo ?>" alt="<?php echo $titre ?>" width="" height="" />        </div>        <h3 style="text-align:center;">Un grand merci à tous les commanditaires qui nous supportent</h3>        <ul class="list-sponsors sponsors-tournament">            <?php                if ($tournoi == 1) {                    $stmt2 = $db->prepare('select * from SPONSORS where actif = 1 and is_tournament_summer = 1 order by name_sponsors ASC');                }                elseif ($tournoi == 2) {                    $stmt2 = $db->prepare('select * from SPONSORS where actif = 1 and is_tournament_winter = 1 order by name_sponsors ASC');                }                $stmt2->execute();                $sponsors = $stmt2->fetchAll(PDO::FETCH_ASSOC);                foreach($sponsors as $sponsor)                {                    $sponsors_name=nl2br(stripslashes($sponsor['name']));                    $logo_sponsors=nl2br(stripslashes($sponsor['logo_sponsors']));                    $url_sponsors=nl2br(stripslashes($sponsor['url']));                    echo "<li class='sponsors-logo'><a href='$url_sponsors' target='_blank' rel='noreferrer'><img src='../$logo_sponsors' alt='$sponsors_name' /></a></li>";                }            ?>        </ul>        <div class="tournament-desc">            <?php echo $texte ?>        </div>        <ul class="tournoi-tarifs">            <?php            $stmt3 = $db->prepare('select * from TOURNAMENT_CATEGORIES where select_tournament = ? ');            $stmt3->execute([$tournoi]);            $results = $stmt3->fetchAll(PDO::FETCH_ASSOC);            foreach($results as $card)            {                $soccer=nl2br(stripslashes($card['t_category_type']));                $category=nl2br(stripslashes($card['t_category_age']));                $fee=nl2br(stripslashes($card['t_category_fee']));                $link=nl2br(stripslashes($card['t_category_link']));                echo "            <li class='t-card'>                <div class='t-card-type'>$category</div>                <div class='t-card-category'>$soccer</div>                <div class='t-card-price'>$$fee<span> par équipe</span></div>                <div class='btn-primary center'><a href='$link' target='_blank' rel='noreferrer'>Inscription</a></div>            </li>                ";            }            ?>        </ul>    </article>		</section>		<?php include("../_includes/footer.inc") ?>