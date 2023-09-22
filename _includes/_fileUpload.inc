<?php
    
    // Function to handle file upload and return the destination path
    function handleFileUpload($file, $uploadDir, $validExtensions, $page, $code) {
        
        $taillemaxi = 2097152;
        $largeurmaxi = 2401;
        $hauteurmaxi = 1601;
        
        $nomoriginel = $file['name'];
        $taillefichier = $file['size'];
        $adresseserveur = $file['tmp_name'];
        $erreurupload = $file['error'];
        
        if($erreurupload==4)
        {
            $fichier="_template-rfc-soccer.jpg";
            $destination=$uploadDir.$fichier;
        }
        else
        {
            if ($erreurupload > 0) retour_erreur($page,1002);
            if ($taillefichier > $taillemaxi) retour_erreur($page,1010);
            

            $extension_upload = strtolower(  substr(  strrchr($nomoriginel, '.')  ,1)  );
            if (!in_array($extension_upload,$validExtensions))  retour_erreur($page,$code);
            
            $image_sizes = getimagesize($adresseserveur);
            if ($image_sizes[0] > $largeurmaxi OR $image_sizes[1] > $hauteurmaxi) retour_erreur($page,1011);
            
            $fichier = basename($nomoriginel);
            $fichier = strtr($fichier,
                'ÀÁÂÃÄÅÇÈÉÊËÌÍÎÏÒÓÔÕÖÙÚÛÜÝàáâãäåçèéêëìíîïðòóôõöùúûüýÿ',
                'AAAAAACEEEEIIIIOOOOOUUUUYaaaaaaceeeeiiiioooooouuuuyy');
            $fichier = preg_replace('/([^.a-z0-9]+)/i', '-', $fichier);
            $destination = $uploadDir.$fichier;
            $destination2 = "../".$destination;
            if (move_uploaded_file($adresseserveur,$destination2))
            {
                $ok="upload réussie";
            }
            else
            {
                retour_erreur($page,1003);
            }
        }
        
        return $destination;
    }
    
    
    
    // Function to handle file upload and return the destination path
    function handleDocUpload($file, $uploadDir, $page) {
        
        $nomoriginel = $file['name'];
        $adresseserveur = $file['tmp_name'];
        $erreurupload = $file['error'];
        
        if ($erreurupload == 4) {
            retour_erreur($page, 1002);
        } else {
            if ($erreurupload > 0) retour_erreur($page,1002);
            
            $extensions_valides = array('jpg', 'jpeg', 'png', 'pdf', 'doc', 'docs', 'docx');
            $extension_upload = strtolower(  substr(  strrchr($nomoriginel, '.')  ,1)  );
            if (!in_array($extension_upload,$extensions_valides))  retour_erreur($page,1023);
            
            $fichier = basename($nomoriginel);
            $fichier = strtr($fichier,
                'ÀÁÂÃÄÅÇÈÉÊËÌÍÎÏÒÓÔÕÖÙÚÛÜÝàáâãäåçèéêëìíîïðòóôõöùúûüýÿ',
                'AAAAAACEEEEIIIIOOOOOUUUUYaaaaaaceeeeiiiioooooouuuuyy');
            $fichier = preg_replace('/([^.a-z0-9]+)/i', '-', $fichier);
            $destination = $uploadDir.$fichier;
            $destination2 = "../".$destination;
            if (move_uploaded_file($adresseserveur,$destination2))
            {
                $ok="upload réussie";
            }
            else
            {
                retour_erreur($page,1003);
            }
        }
        
        return $destination;
    
    }

?>