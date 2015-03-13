<?php

class GeoJSON {
	
	private static $type = ['Geometry', 'Feature', 'FeatureCollection'];
	private $crs = '';
	
	/**
	 * setCrs
	 * 
	 * @param Geometry|Feature|FeatureCollection $obj
	 * 
	 * @throws InvalidArgumentException
	 * 
	 */
	public function setCrs($obj) {
		
		if(in_array(get_class($obj), self::$type)) {
			
			$this->crs = self::createCrs($obj);
			
		} else {
			
			throw new InvalidArgumentException('Parameter $obj must be a valid GeoJSON object. Valid GeoJSON object are: ' . implode(', ', self::$type));
		}
	}
	
	/**
	 * createCrs
	 * 
	 * Dependent to the internal system / to define
	 * 
	 * @todo Achieve the method
	 * 
	 * @param Geometry|Feature|FeatureCollection $obj
	 * 
	 * @return string
	 */
	private static function createCrs($obj) {
		//@TODO
		
		return '';
	}
	
	/**
	 * getCrs
	 * 
	 * @throws InvalidArgumentException
	 * 
	 * @return string
	 */
	public function getCrs() {
		
		if(!empty($this->crs)) {
			
			return $this->crs;
			
		} else {
			
			throw new InvalidArgumentException('You must use setCrs with a valid GeoJSON object parameter before using getCrs method.');
		}
	}
}