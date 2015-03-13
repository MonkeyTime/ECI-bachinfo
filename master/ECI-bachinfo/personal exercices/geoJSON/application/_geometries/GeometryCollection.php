<?php

class GeometryCollection {
	
	use TGeometry;
	
	protected $geometries = array();
	
	public function addGeometry(Geometry $geometry) {
		
		$this->geometries[] = $geometry;
		
		return $this;
	}
	
	public function getGeometries() {
		
		return $this->geometries;
	}
}