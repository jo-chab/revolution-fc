<?php
    
    // Function to handle file upload and return the destination path
    function handleFileUpload($file, $uploadDir, $validExtensions, $page, $errorCode) {
        $maxSize = 2097152; // 2MB
        $maxWidth = 2401;
        $maxHeight = 1601;
        
        if ($file['error'] === UPLOAD_ERR_NO_FILE) {
            return "_template-rfc-soccer.jpg"; // Assuming this is a default or fallback image
        }
        
        if ($file['error']) {
            retour_erreur_content($page, 1002, 'errorDetail', $file['error']); // Example error code for file upload error
        }
        
        if ($file['size'] > $maxSize) {
            retour_erreur($page, 1010); // File size too large
        }
        
        $extension = strtolower(pathinfo($file['name'], PATHINFO_EXTENSION));
        if (!in_array($extension, $validExtensions)) {
            retour_erreur($page, 1024); // Invalid file type
        }
        
        $imageSizes = getimagesize($file['tmp_name']);
        if (!$imageSizes || $imageSizes[0] > $maxWidth || $imageSizes[1] > $maxHeight) {
            retour_erreur($page, 1011); // Image dimensions exceed maximum allowed
        }
        
        $sanitizedFileName = preg_replace('/[^a-zA-Z0-9_-]/', '_', $file['name']);
        $uniqueFileName = time() . "_" . $sanitizedFileName . '.' . $extension;
        $destinationPath = $uploadDir . $uniqueFileName;
        $destinationFullPath = "../" . $destinationPath;
        
        if (!move_uploaded_file($file['tmp_name'], $destinationFullPath)) {
            retour_erreur($page, 1003); // Failed to move uploaded file
        }
        
        return $destinationPath;
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