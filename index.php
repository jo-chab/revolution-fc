<?php    include("_includes/session_test.inc");    include("_includes/_revolutionfc.inc");            // Config contact du site    $stmtConfig = "SELECT * FROM CONFIG_hero_home LIMIT 1";    $resultConfig = $db->query($stmtConfig);        if ($resultConfig->rowCount() > 0) {        $row = $resultConfig->fetch(PDO::FETCH_ASSOC);        extract($row);                $heroText = nl2br(stripslashes($hero_headline));        $btnText = nl2br(stripslashes($hero_button));        $heroImg = $hero_image;        $heroLink = nl2br(stripslashes($hero_link));        $external = $external_link;        if ($external == 0){            $linkType = '';        } else {            $linkType = 'target="_blank"';        }    }?>    <!doctype html>    <html lang="fr"><head>    <meta charset="UTF-8">    <title>R&eacute;volution FC - Bienvenue</title>        <?php        include("_includes/head.inc");        echo "<body class='w-home'>";        include("_includes/header.inc");    ?>            <!-- START OF THE HERO IMAGE SECTION -->    <section class="w-hero">        <article class="wrapper bg-img-content" style="background-image: url(<?php echo $heroImg ?>)">            <div class="hero-overlay-gradient"></div>            <div class="hero-overlay-content">                <h1><?php echo $heroText ?></h1>                <a class="btn-secondary ghost-white icon icon-hero" href="<?php echo $heroLink ?>" <?php echo $linkType ?>><?php echo $btnText ?></a>            </div>        </article>    </section>    <!-- END OF THE HERO IMAGE SECTION -->            <section id="hp-news_list">                <article class="wrapper">            <h2>Derni&egrave;res nouvelles</h2>            <div class="w-news grid-system col-3">                                <?php                    $stmt = $db->prepare('select * from ACTUALITE,ACTUALITE_SECTION where id_actu_section = id_section AND actif = 1 order by date_actu DESC LIMIT 4');                    $stmt->execute();                                        $cpt2 = 0;                    $news_number = 3;                                        $results = $stmt->fetchAll(PDO::FETCH_ASSOC);                    foreach ($results as $result) //while ($row = $stmt->fetch() and $cpt2<3)                    {                        if ($cpt2 < $news_number) {                            setlocale(LC_TIME, 'fr_FR');                                                        $date = date('Y-m-d', strtotime($result['date_actu']));                            $date_text = strftime("%d %B %G", strtotime($date));                            $date_text = nl2br(stripslashes(utf8_encode($date_text)));                            $titre = nl2br(stripslashes($result['titre']));                            $bgImg = nl2br(stripslashes($result['photo']));                            $categorie = nl2br(stripslashes($result['section_name']));                            $id_actu = $result['id_actu'];                                                        $cpt2++;                                                        echo "                        <a href='nouvelles/nouvelles_details?actu=$id_actu'>                            <div class='news-card'>								<div class='news-card-img' style='background-image:url($bgImg);'></div>								<div class='news-card-vignette'>								    <div class='news-card-info'>                                        <div class='news-category'>$categorie</div>									    <h6 class='text-dates'>$date_text</h6>                                    </div>                                    <h3 class='news-card-headline'>$titre</h3>								</div>							</div>                        </a>                        ";                                                }                    }                ?>                        </div>            <div class="w-btn">                <a class="btn-tertiary btn-text large icon i-more" href="nouvelles/">D&eacute;couvrir toutes les actualit&eacute;s</a>            </div>        </article>        </section>            <section class="w-events">        <article class="wrapper">            <h3>Nos prochains évènements</h3>            <div class="w-cards">                                <?php                    // Get the current date                    $currentDate = date('Y-m-d');                                        $stmt = $db->prepare('SELECT * FROM EVENTS, FIELDS WHERE id_field = event_venue AND event_date >= :currentDate AND is_actif = 1 ORDER BY event_date ASC LIMIT 3');                    $stmt->bindParam(':currentDate', $currentDate);                    $stmt->execute();                                        // Check if there are any rows returned                    if ($stmt->rowCount() === 0) {                        echo "<h5 id='title-no-event'>Aucun(s) évènement(s) à venir</h5>";                    } else {                        $cpt = 0;                        $event_number = 3;                                                $results = $stmt->fetchAll(PDO::FETCH_ASSOC);                                                foreach ($results as $result) {                            if ($cpt < $event_number) {                                setlocale(LC_TIME, 'fr_FR');                                                                $element = $result['id_event'];                                                                $date = date('Y-m-d', strtotime($result['event_date']));                                $date_end = date('Y-m-d', strtotime($result['event_date_end']));                                $date_text = '';                                                                // Check if event_date_end is not empty and not "0000-00-00"                                if (!empty($result['event_date_end']) && $result['event_date_end'] != '0000-00-00') {                                    $startMonth = strftime("%B", strtotime($date));                                    $endMonth = strftime("%B", strtotime($date_end));                                                                        // Check if the start and end months are the same                                    if ($startMonth == $endMonth) {                                        $date_text .= strftime("%d", strtotime($date));                                    } else {                                        $date_text .= strftime("%d %B", strtotime($date));                                    }                                                                        $date_text .= ' - ';                                    $date_text .= strftime("%d %B %G", strtotime($date_end));                                } else {                                    $date_text .= strftime("%d %B %G", strtotime($date));                                }                                                                $date_text = nl2br(stripslashes(utf8_encode($date_text)));                                $title = nl2br(stripslashes($result['event_name']));                                $titleUrl = urlencode(str_replace(' ', '-', ($result['event_name']))); // Generate a URL-friendly version of the event title                                $venue = nl2br(stripslashes($result['field_name']));                                                                $cpt++;                                                                echo "                <a href='/evenements/detail?id=$element&title=$titleUrl' data-event-id='$element' data-event-title='$titleUrl'>                    <div class='card-events event-el'>                        <h6 class='event-date'>$date_text</h6>                        <h4 class='event-title'>$title</h4>                        <h6 class='event-venue'>$venue</h6>                    </div>                </a>                                ";                            }                        }                    }                                ?>            </div>            <div class="w-btn">                <a class="btn-tertiary btn-text large icon i-more" href="/evenements/">Plus d'évènements</a>            </div>        </article>    </section>        <section class="w-jobs">                <article class="wrapper">                        <h2>Offre(s) d'emploi</h2>            <ul class="list-jobs">                <?php                    $stmt2 = $db->prepare('select * from EMPLOIS order by id_job ASC');                    $stmt2->execute();                                        $results2 = $stmt2->fetchAll(PDO::FETCH_ASSOC);                    if (empty($results2)) {                                                echo "                    <li>                        <h4>Il n'y a aucune offre d'emploi actuellement</h4>                    </li>";                                            } else {                        foreach ($results2 as $result2) {                            $titre = nl2br(stripslashes($result2['job_name']));                            $desc = nl2br(stripslashes($result2['job_desc']));                            $link = $result2['job_doc'];                                                        echo "                    <li class='job-el'>                        <div class='job-infos'>                            <h4>$titre</h4>                            <p>$desc</p>                        </div>                        <a class='btn-primary btn-card' href='$link' target='_blank'>Postuler</a>                    </li>";                        }                    }                ?>            </ul>                </article>        </section>            <!-- START OF THE CONTACT SECTION -->    <section class="contact">        <article class="grid-layout col-2">            <div class="hp-google-map">                <iframe src="<?php echo $clubMap ?>" width="100%" height="100%" style="border:0;" allowfullscreen="" loading="lazy"></iframe>            </div>            <div class="hp-contact-info">                <div class="contact-info-details">                    <h4>Coordonn&eacute;es</h4>                    <p><?php echo $adressClub ?></p>                    <p><span class="text-highlight">T&eacute;l&eacute;phone :</span> <?php echo $phone ?></p>                    <p><span class="text-highlight">Courriel :</span> <?php echo $emailAdmin ?></p>                </div>                <div class="contact-info-details">                    <h4>Heures d'ouverture</h4>                    <p><?php echo $hours ?></p>                </div>            </div>        </article>    </section>    <!-- END OF THE CONTACT SECTION -->            <!-- START OF THE SPONSORS SECTION -->    <section style="background-color: white;">        <article class="wrapper">            <ul class="list-sponsors">                <?php                    $stmt2 = $db->prepare('select * from SPONSORS, SPONSORS_event where id_sponsors = sponsor_id and actif = 1 and sponsor_event = 0 order by name_sponsors ASC');                    $stmt2->execute();                                        $cpt3 = 0;                    while ($row2 = $stmt2->fetch()) {                        extract($row2);                        $name = nl2br(stripslashes($name_sponsors));                        $logo_sponsors = nl2br(stripslashes($logo_sponsors));                        $url_sponsors = nl2br(stripslashes($url));                        $cpt3++;                        echo "<li class='sponsors-logo'><a href='$url_sponsors' target='_blank' rel='noreferrer'><img src='../$logo_sponsors' alt='$name' /></a></li>";                    }                ?>            </ul>        </article>    </section>    <!-- END OF THE SPONSORS SECTION --><?php    include("_includes/footer.inc");?>