<?php	session_start();	include("../_includes/_revolutionfc.inc");    if (get_magic_quotes_gpc()) {        $login = stripslashes($_POST['zt_email']);        $pass = stripslashes($_POST['zt_password']);    } else {        $login = $_POST['zt_email'];        $pass = $_POST['zt_password'];    }            /* ======== LOGIN ============== */        $stmt = $db->prepare('SELECT * FROM USERS WHERE email = ?');        if ($stmt->execute([$login])) {                $user = $stmt->fetch(PDO::FETCH_ASSOC);        if (!$user || !password_verify($pass, $user['password'])) {            header('Location: ' . $websiteUrl . 'admin/login?m=5');            exit();        }                $actif = $user['actif'];        $email = $user['email'];        $type = $user['type'];        $id_user = $user['id_user'];        $username = $user['user_fn'];                $_SESSION['auth'] = $actif;        $_SESSION['email'] = $email;        $_SESSION['type'] = $type;        $_SESSION['user'] = $id_user;        $_SESSION['username'] = $username;                if ($actif != 1) {            header('Location: ' . $websiteUrl . '?m=6');            exit();        } else {            if ($type >= 3) {                header('Location: ' . $websiteUrl . 'admin/index?p=1');                exit();            } else {                header('Location: ' . $websiteUrl . '?m=11');                exit();            }        }    } else {        header('Location: ' . $websiteUrl . 'admin/login?m=5');    }?>