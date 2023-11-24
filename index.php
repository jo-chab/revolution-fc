<?php    include("_includes/session_test.inc");    include("_includes/_revolutionfc.inc");            // Config contact du site    $stmtConfig = "SELECT * FROM CONFIG_hero_home LIMIT 1";    $resultConfig = $db->query($stmtConfig);        if ($resultConfig->rowCount() > 0) {        $row = $resultConfig->fetch(PDO::FETCH_ASSOC);        extract($row);                $heroText = nl2br(stripslashes($hero_headline));        $btnText = nl2br(stripslashes($hero_button));        $heroImg = $hero_image;        $heroLink = nl2br(stripslashes($hero_link));    }    ?>    <!doctype html>    <html lang="fr"><head>    <meta charset="UTF-8">    <title>R&eacute;volution FC - Bienvenue</title>        <?php        include("_includes/head.inc");        echo "<body class='w-home'>";        include("_includes/header.inc");    ?>            <!-- START OF THE HERO IMAGE SECTION -->    <section class="w-hero">        <article class="wrapper bg-img-content" style="background-image: url(<?php echo $heroImg ?>)">            <div class="hero-overlay-gradient"></div>            <div class="hero-overlay-content">                <h1><?php echo $heroText ?></h1>                <a class="btn-secondary ghost-white icon icon-hero" href="<?php echo $heroLink ?>" ><?php echo $btnText ?></a>            </div>        </article>    </section>    <!-- END OF THE HERO IMAGE SECTION -->            <section id="hp-news_list">                <article class="wrapper">            <h2>Derni&egrave;res nouvelles</h2>            <div class="w-news grid-system grid-col-3">                                <?php                    $stmt = $db->prepare('select * from ACTUALITE,ACTUALITE_SECTION where id_actu_section = id_section AND actif = 1 order by date_actu DESC LIMIT 4');                    $stmt->execute();                                        $cpt2 = 0;                    $news_number = 3;                                        $results = $stmt->fetchAll(PDO::FETCH_ASSOC);                    foreach ($results as $result) //while ($row = $stmt->fetch() and $cpt2<3)                    {                        if ($cpt2 < $news_number) {                            setlocale(LC_TIME, 'fr_FR');                                                        $date = date('Y-m-d', strtotime($result['date_actu']));                            $date_text = strftime("%d %B %G", strtotime($date));                            $date_text = nl2br(stripslashes(utf8_encode($date_text)));                            $titre = nl2br(stripslashes($result['titre']));                            $bgImg = nl2br(stripslashes($result['photo']));                            $categorie = nl2br(stripslashes($result['section_name']));                            $id_actu = $result['id_actu'];                                                        $cpt2++;                                                        echo "                        <a href='nouvelles/nouvelles_details?actu=$id_actu'>                            <div class='news-card'>								<div class='news-card-img' style='background-image:url($bgImg);'></div>								<div class='news-card-vignette'>								    <div class='news-card-info'>                                        <div class='news-category'>$categorie</div>									    <h6 class='text-dates'>$date_text</h6>                                    </div>                                    <h3 class='news-card-headline'>$titre</h3>								</div>							</div>                        </a>                        ";                                                }                    }                ?>                        </div>            <a class="btn-tertiary icon i-long-arrow-table" href="nouvelles/">D&eacute;couvrir toutes les actualit&eacute;s</a>        </article>        </section>        <section class="w-jobs">                <article class="wrapper">                        <h2>Offre(s) d'emploi</h2>            <ul class="list-jobs">                <?php                    $stmt2 = $db->prepare('select * from EMPLOIS order by id_job ASC');                    $stmt2->execute();                                        $results2 = $stmt2->fetchAll(PDO::FETCH_ASSOC);                    if (empty($results2)) {                                                echo "                    <li>                        <h4>Il n'y a aucune offre d'emploi actuellement</h4>                    </li>";                                            } else {                        foreach ($results2 as $result2) {                            $titre = nl2br(stripslashes($result2['job_name']));                            $desc = nl2br(stripslashes($result2['job_desc']));                            $link = $result2['job_doc'];                                                        echo "                    <li class='job-el'>                        <div class='job-infos'>                            <h4>$titre</h4>                            <p>$desc</p>                        </div>                        <a class='btn-primary btn-card' href='$link' target='_blank'>Postuler</a>                    </li>";                        }                    }                ?>            </ul>                </article>        </section>            <!-- START OF THE CONTACT SECTION -->    <section class="contact">        <article class="grid-layout col-2">            <div class="hp-google-map">                <iframe src="<?php echo $clubMap ?>" width="100%" height="100%" style="border:0;" allowfullscreen="" loading="lazy"></iframe>            </div>            <div class="hp-contact-info">                <div class="contact-info-details">                    <h4>Coordonn&eacute;es</h4>                    <p><?php echo $adressClub ?></p>                    <p><span class="text-highlight">T&eacute;l&eacute;phone :</span> <?php echo $phone ?></p>                    <p><span class="text-highlight">Courriel :</span> <?php echo $emailAdmin ?></p>                </div>                <div class="contact-info-details">                    <h4>Heures d'ouverture</h4>                    <p><?php echo $hours ?></p>                </div>            </div>        </article>    </section>    <!-- END OF THE CONTACT SECTION -->            <!-- START OF THE SPONSORS SECTION -->    <section style="background-color: white;">        <article class="wrapper">            <ul class="list-sponsors">                <?php                    $stmt2 = $db->prepare('select * from SPONSORS where actif = 1 and is_club = 1 order by name_sponsors ASC');                    $stmt2->execute();                                        $cpt3 = 0;                    while ($row2 = $stmt2->fetch()) {                        extract($row2);                        $name = nl2br(stripslashes($name_sponsors));                        $logo_sponsors = nl2br(stripslashes($logo_sponsors));                        $url_sponsors = nl2br(stripslashes($url));                        $cpt3++;                        echo "<li class='sponsors-logo'><a href='$url_sponsors' target='_blank' rel='noreferrer'><img src='../$logo_sponsors' alt='$name' /></a></li>";                    }                ?>            </ul>        </article>    </section>    <!-- END OF THE SPONSORS SECTION --><?php    include("_includes/footer.inc");?>