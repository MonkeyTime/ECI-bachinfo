<?php

$geo1 = (new GeoJSON)->setCrs(($geom1 = (new Geometry)->set(new Point())));
$crs1 = $geo1->getCrs();

$geo2 = (new GeoJSON)->setCrs(($geom2 = (new Geometry)->set(new LineString())));
$crs2 = $geo2->getCrs();

$geo3 = (new GeoJSON)->setCrs(($geom3 = (new Geometry)->set(new LineString())));
$crs3 = $geo3->getCrs();

$feat1 = (new GeoJSON)->setCrs((new Feature)->set($geom1->get(), $geom1->getProperties()));
$crsf1 = $feat1->getCrs();

$feat2 = (new GeoJSON)->setCrs((new Feature)->set($geom2->get(), $geom2->getProperties()));
$crsf2 = $feat2->getCrs();

$featN = (new GeoJSON)->setCrs((new Feature)->set($geom3->get(), $geom3->getProperties()));
$crsf3 = $featN->getCrs();


$coll = (new GeoJSON)->setCrs((new FeatureCollection)->addFeature($feat1)); //@todo php5.6 floc decompressor ???
$crsc = $coll->getCrs();