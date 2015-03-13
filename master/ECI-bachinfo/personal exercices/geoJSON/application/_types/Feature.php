<?php

class Feature {
	
	private $id = null;
	private $geometry = null;
	private $properties = null;
	
	public function set(Geometry $geometry, $id = null) {
		
		if(isset($id)) {
			
			$this->id = $id;
		}
		
		$this->geometry = $geometry;
	}
	
	public function setProperties($properties = null) {

		if(!is_null($properties) && !is_object($properties)) {
			
			throw new InvalidArgumentException('Parameter $properties must be a valid object value.');
		}
		
		$this->properties = $properties;
	}
}
