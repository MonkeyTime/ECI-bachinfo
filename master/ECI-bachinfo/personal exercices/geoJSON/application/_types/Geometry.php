<?php

class Geometry {
	
	private static $type = ['Point', 'MultiPoint', 'LineString', 'MultiLineString', 'Polygon', 'MultiPolygon', 'GeometryCollection'];
	private $geometry = null;
	private $properties = [];
	
	public function set($obj) {
		
		if(!in_array(get_class($obj), self::$type)) {
				
			throw new InvalidArgumentException('Parameter must be a valid GeoJSON Geometry object. Valid GeoJSON Geometry object are: ' . implode(', ', self::$type));
		}
		
		$this->geometry = $obj;
	}
	
	public function get() {
		
		return $this->geometry;
	}
	
	public function setProperties($properties = array()) {
		
		$this->properties = $properties;
	}
	
	public function getProperties() {
		
		return $this->properties;
	}
}