<?php

class MultiLineString {
	
	use TGeometry;
	use TCoordinate;
	
	public function addLineString(LineString $lineString) {	
		
		$this->coordinates[] = $lineString->getCoordinates();
		
		return $this;
	}
}