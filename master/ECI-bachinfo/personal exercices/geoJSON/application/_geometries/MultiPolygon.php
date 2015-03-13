<?php

class MultiPolygon {

	use TGeometry;
	use TCoordinate;
	
	public function addPolygon(Polygon $polygon) {
			
		$this->coordinates[] = $polygon->getCoordinates();
		
		return $this;
	}
}
