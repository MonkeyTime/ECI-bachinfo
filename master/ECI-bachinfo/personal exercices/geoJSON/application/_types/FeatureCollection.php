<?php

class FeatureCollection {
	
	private $features = array();
	
	public function addFeature(Feature $feature) {
		
		$this->features[] = $feature;
		
		return $this;
	}
	
	public function getFeatures() {
		
		return $this->features;
	}
}