<?php

// autoload_static.php @generated by Composer

namespace Composer\Autoload;

class ComposerStaticInit7c1fe5d938c752f5ab56abc04f0989d6
{
    public static $files = array (
        '2cffec82183ee1cea088009cef9a6fc3' => __DIR__ . '/..' . '/ezyang/htmlpurifier/library/HTMLPurifier.composer.php',
    );

    public static $prefixLengthsPsr4 = array (
        'P' => 
        array (
            'PHPMailer\\PHPMailer\\' => 20,
        ),
    );

    public static $prefixDirsPsr4 = array (
        'PHPMailer\\PHPMailer\\' => 
        array (
            0 => __DIR__ . '/..' . '/phpmailer/phpmailer/src',
        ),
    );

    public static $prefixesPsr0 = array (
        'H' => 
        array (
            'HTMLPurifier' => 
            array (
                0 => __DIR__ . '/..' . '/ezyang/htmlpurifier/library',
            ),
        ),
    );

    public static $classMap = array (
        'Composer\\InstalledVersions' => __DIR__ . '/..' . '/composer/InstalledVersions.php',
    );

    public static function getInitializer(ClassLoader $loader)
    {
        return \Closure::bind(function () use ($loader) {
            $loader->prefixLengthsPsr4 = ComposerStaticInit7c1fe5d938c752f5ab56abc04f0989d6::$prefixLengthsPsr4;
            $loader->prefixDirsPsr4 = ComposerStaticInit7c1fe5d938c752f5ab56abc04f0989d6::$prefixDirsPsr4;
            $loader->prefixesPsr0 = ComposerStaticInit7c1fe5d938c752f5ab56abc04f0989d6::$prefixesPsr0;
            $loader->classMap = ComposerStaticInit7c1fe5d938c752f5ab56abc04f0989d6::$classMap;

        }, null, ClassLoader::class);
    }
}
