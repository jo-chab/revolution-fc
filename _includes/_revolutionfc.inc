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
    
    function retour_erreur($page, $code_erreur)
    {
        header('Location: https://www.revolutionfc.ca/admin/index.php?p=' . $page . '&m=' . $code_erreur);
        exit;
    }

?>