<?php
    
    $host = "64.34.156.161";
    $login = "revol932";
    $pass = "p0kjws9yb3";
    $base = "revol932_rfc_website";
    global $db;
    
    
    try {
        $db = new PDO("mysql:host={$host};dbname=$base;charset=utf8", $login, $pass);
    } catch (PDOException $e) {
        echo 'Error connecting to the Database';
    }
    
    
    
    // Config club du site
    $stmtConfig = "SELECT * FROM CONFIG_admin LIMIT 1";
    $resultConfig = $db->query($stmtConfig);
    
    if ($resultConfig->rowCount() > 0) {
        $row3 = $resultConfig->fetch(PDO::FETCH_ASSOC);
        extract($row3);
        
        $websiteUrl = $config_url;
        $root = $config_path;
    }
    
    // Config info du club
    $stmtG1 = "SELECT * FROM CONFIG_contact LIMIT 1";
    $resultG1 = $db->query($stmtG1);
    
    if ($resultG1->rowCount() > 0) {
        $row1 = $resultG1->fetch(PDO::FETCH_ASSOC);
        extract($row1);
        
        $phone = $club_phone;
        $emailClub = $club_email;
        $emailAdmin = $club_email_2;
        $adressClub = $adress_1;
        $adressText = str_replace('<br />', "", $adressClub);
        $hours = $club_hours;
        $hoursText = str_replace('<br />', "", $hours);
        $clubMap = $club_map;
    }
    
    
    // Config liens du site
    $stmtG2 = "SELECT * FROM CONFIG_links LIMIT 1";
    $resultG2 = $db->query($stmtG2);
    
    if ($resultG2->rowCount() > 0) {
        $row2 = $resultG2->fetch(PDO::FETCH_ASSOC);
        extract($row2);
        
        $registrationUrl = $link_registration;
        $storeUrl = $link_store;
        $recuImpots = $link_tax_receipt;
        $facebook = $link_facebook;
        $instagram = $link_instagram;
    }
    
    function retour_erreur($page, $code_erreur)
    {
        header('Location: https://www.revolutionfc.ca/admin/index.php?p=' . $page . '&m=' . $code_erreur);
        exit;
    }



?>