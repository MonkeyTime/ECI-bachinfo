<?php

class Position {
	
	public $a = null;
	public $b = null;
	public $c = null;
	
	/**
	 * setPointCoordinates
	 * 
	 * @param number $x
	 * @param number $y
	 * @param number $z (optional)
	 */
	public function setPointCoordinates($x, $y, $z = null) {
	
		if(!is_int($x) || !is_float($x)) {
			
			throw new InvalidArgumentException('parameter $x must be a float or a int valid value.');
		}
		
		if(!is_int($y) || !is_float($y)) {
				
			throw new InvalidArgumentException('parameter $y must be a float or a int valid value.');
		}
		
		if(isset($z) && (!is_int($z) || !is_float($z))) {
		
			throw new InvalidArgumentException('parameter $z must be a float or a int valid value.');
		}
		
		$this->a = $x;
		$this->b = $y;
		$this->c = isset($z) ? $z : null;
	}
	
	/**
	 * setProjectedCoordinates
	 * 
	 * @todo is_float or is_int is exact ????
	 * 
	 * @param number $easting
	 * @param number $northing
	 * @param number $altitude (optional)
	 */
	public function setProjectedCoordinates($easting, $northing, $altitude = null) {
		
		if(!is_int($easting) || !is_float($easting)) {
				
			throw new InvalidArgumentException('parameter $easting must be a float or a int valid value.');
		}
		
		if(!is_int($northing) || !is_float($northing)) {
		
			throw new InvalidArgumentException('parameter $northing must be a float or a int valid value.');
		}
		
		if(isset($altitude) && (!is_int($altitude) || !is_float($altitude))) {
		
			throw new InvalidArgumentException('parameter $altitude must be a float or a int valid value.');
		}
	
		$this->a = $easting;
		$this->b = $northing;
		$this->c = isset($altitude) ? $altitude : null;
	}
	
	/**
	 * setGeographicCoordinates
	 * 
	 * @param number $longitude
	 * @param number $latitude
	 * @param number $altitude (optional)
	 */
	public function setGeographicCoordinates($longitude, $latitude, $altitude) {
		
		if(!is_int($longitude) || !is_float($longitude)) {
				
			throw new InvalidArgumentException('parameter $longitude must be a float or a int valid value.');
		}
		
		if(!is_int($latitude) || !is_float($latitude)) {
		
			throw new InvalidArgumentException('parameter $latitude must be a float or a int valid value.');
		}
		
		if(isset($altitude) && (!is_int($altitude) || !is_float($altitude))) {
		
			throw new InvalidArgumentException('parameter $altitude must be a float or a int valid value.');
		}
	
		$this->a = $longitude;
		$this->b = $latitude;
		$this->c = isset($altitude) ? $altitude : null;
	}
	
}