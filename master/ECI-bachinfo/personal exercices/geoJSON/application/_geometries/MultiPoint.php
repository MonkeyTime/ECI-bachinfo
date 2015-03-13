<?php

class MultiPoint {
	
	use TGeometry;
	use TCoordinate;
	
	public function addPoint(Point $point) {
			
		$this->coordinates[] = $point->getCoordinates();
		
		return $this;
	}
}