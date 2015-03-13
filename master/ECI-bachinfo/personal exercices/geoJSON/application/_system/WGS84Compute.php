<?php

/**
 * @todo verify all methods and define+add elsewhere rad2deg and deg2rad is needed
 * @link More infos http://en.wikipedia.org/wiki/Geodetic_datum
 *
 */
class WGS84Compute {
	
	/**
	 * Semi-major Axis (a)
	 * 
	 * 6378137 meters
	 * 
	 * @var float In meter
	 */
	const EARTH_RADIUS = 6378137.0;
	
	/**
	 * Flattening (f)
	 * 
	 * @todo uncomment
	 * 
	 * @var float
	 */
	//@todo const EARTH_FLATTENING = 1/298.257223563; //PHP5.6 necessary for basic math in const or const in a const
	
	/**
	 * Semi-minor axis (b)
	 * 
	 * @todo uncomment
	 * 
	 * b = a (1 – f)
	 * 
	 */
	
	//@todo const EARTH_ELLIPSOID_REFERENCE = EARTH_RADIUS * (1 - EARTH_FLATTENING); //PHP5.6 necessary for basic math in const or const in a const
	
	/**
	 * earth assumed is a perfect sphere
	 * 
	 * @var float
	 */
	const EARTH_ASSUMED_PERFECT_SPHERE = 40075016.69;
	
	private $latitude = null;
	private $longitude = null;
	private $deltaLatitude = null;
	private $deltaLongitude = null;
	private $northing = null;
	private $easting = null;
	private $bearing = null;
	private $gcd = null;
	private $x = null;
	private $y = null;
	
	/**
	 * precisionOnePercent
	 * 
	 * assume the Earth is a perfect sphere (~1% precision lost)
	 * 
	 * @todo To test
	 * @todo uncomment (PHP5.6 required)
	 * 
	 * @tutorial Sets deltaLatitude, deltaLongitude, northing, easting, gcd
	 * @link http://inventeksys.com/GPS_Facts_Great_Circle_Distances.pdf
	 * 
	 * @param Point $a
	 * @param Point $b
	 */
	public function precisionOnePercent(Point $a, Point $b) {

		$this->deltaLatitude = $b->getCoordinates()[0] - $a->getCoordinates()[0];
		$this->deltaLongititude = $b->getCoordinates()[1] - $a->getCoordinates()[1];
		
		$this->northing = $this->deltaLatitude / (360 * EARTH_ASSUMED_PERFECT_SPHERE); //@todo To test. ∆φ / 360 * 2πRE (∆φ in degrees) 
		$this->easting = $this->deltaLongitude / (360 * EARTH_ASSUMED_PERFECT_SPHERE * cos($a->getCoordinates()[0])); //@todo To test. ∆λ / 360 * 2πRE cos (φ1) (∆λ in degrees)
	
		//@todo $this->gcd = ($this->northing ** 2 + $this->easting ** 2) ** 1/2; //@todo To test. (Northing exp2 + Easting exp2) exp1/2 - in meters
	}
	
	/**
	 * precisionWithEllipsoidReference
	 *
	 * assume the Earth is a perfect sphere (precision lost)
	 *
	 * @todo To Test
	 * @todo uncomment (PHP5.6 required)
	 * 
	 * @tutorial Sets deltaLatitude, deltaLongitude, northing, easting, gcd
	 * @link http://inventeksys.com/GPS_Facts_Great_Circle_Distances.pdf
	 * 
	 * @param Point $a
	 * @param Point $b
	 */
	public function precisionWithEllipsoidReference(Point $a, Point $b) {
	
		$this->deltaLatitude = $b->getCoordinates()[0] - $a->getCoordinates()[0];
		$this->deltaLongititude = $b->getCoordinates()[1] - $a->getCoordinates()[1];
	
		$this->northing = $this->deltaLatitude / (360 * (2 * pi() * EARTH_ELLIPSOID_REFERENCE)); //@todo To test. ∆φ / 360 * 2πb (∆φ in degrees)
		$this->easting = $this->deltaLongitude / (360 * EARTH_ASSUMED_PERFECT_SPHERE * cos($a->getCoordinates()[0])); //@todo To test. ∆λ / 360 * 2πRE cos (φ1) (∆λ in degrees)
	
		//@todo $this->gcd = ($this->northing ** 2 + $this->easting ** 2) ** 1/2; //@todo To test. (Northing exp2 + Easting exp2) exp1/2 - in meters
	}
	
	/**
	 * precisionByAircraftGuidance
	 *
	 * assumes that the Earth is a perfect sphere of radius RE (~0.367% precision lost)
	 *
	 * @todo To test
	 * @todo uncomment (PHP5.6 required)
	 * 
	 * @tutorial Sets deltaLatitude, deltaLongitude, x, y, bearing (x / y), gcd
	 * @link http://inventeksys.com/GPS_Facts_Great_Circle_Distances.pdf
	 * 
	 * @param Point $a
	 * @param Point $b
	 */
	public function precisionByAircraftGuidance(Point $a, Point $b) {
	
		$this->deltaLatitude = $b->getCoordinates()[0] - $a->getCoordinates()[0];
		$this->deltaLongititude = $b->getCoordinates()[1] - $a->getCoordinates()[1];
		
		$this->x = cos($b->getCoordinates()[0]) * sin($this->deltaLongititude); //@todo To test.  X = cos (φ2) sin (∆λ)
		$this->y =  sin($this->deltaLatitude) + (cos($b->getCoordinates()[0]) * sin($a->getCoordinates()[0])) * (1 - cos($this->deltaLongititude)); //@todo To test.  Y = sin (∆φ) + cos (φ2) sin (φ1) [1 – cos (∆λ)]
	
		$this->bearing = atan2($this->x, $this->y); //@todo To test.  tan exp-1 (X/Y) == atan2 func ?? && x, y parameters in radian or degree ??
		
		//@todo $this->gcd = EARTH_RADIUS * (atan2(($this->y * cos($this->bearing) + $this->x * sin($this->bearing)) / (cos($this->deltaLatitude) - (cos($a->getCoordinates()[0]) * cos($b->getCoordinates()[0]) * (1 - cos($this->deltaLatitude)))))); //@todo To test.  tan exp-1 (X/Y) == atan2 func ?? && x, y parameters in radian or degree ??
		/*
		 * P = Y cos (Ψ2,1) + X sin (Ψ2,1)
		 * 1 + Z = cos (∆φ) – cos (φ1) cos (φ2) [1 – cos (∆φ)]
		 * Θ2,1 = tan-1[P / (1 + Z)]
		 * GCD = RE Θ2,1
		 */
	}
	
	/**
	 * precisionMagnavox
	 *
	 * assumes that the Earth is an ellipsoid Earth (best precision here)
	 *
	 * @todo To test
	 * @todo Achieve the method (follow the link)
	 *
	 * @tutorial Sets 
	 * @link http://inventeksys.com/GPS_Facts_Great_Circle_Distances.pdf
	 *
	 * @param Point $a
	 * @param Point $b
	 */
	public function precisionMagnavox(Point $a, Point $b) {
	
		$this->deltaLatitude = $b->getCoordinates()[0] - $a->getCoordinates()[0];
		$this->deltaLongititude = $b->getCoordinates()[1] - $a->getCoordinates()[1];

	
		$this->bearing = 0; //@todo To test.
	
		$this->gcd = 0; //@todo To test.
	}
}