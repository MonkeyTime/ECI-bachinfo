<?php

class Polygon {

	use TGeometry;
	use TCoordinate;
	
	public function addMultiPoint(MultiPoint $multiPoints) {
			
		$this->coordinates[] = $multiPoints->getCoordinates();
	}
	
	public function addHole(MultiPoint $multiPoints) {
		
		$this->coordinates[] = $multiPoints->getCoordinates();
		
		return $this;
	}
}
