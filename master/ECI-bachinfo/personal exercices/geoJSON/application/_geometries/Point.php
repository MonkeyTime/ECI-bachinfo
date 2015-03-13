<?php

class Point {
	
	use TGeometry;
	use TCoordinate;
	
	public function setCoordinates(Position $position) {
		
		$this->coordinates = [$position->a, $position->b];
		
		if(isset($position->c)) {
			
			$this->coordinates = array_push($this->coordinates, $position->c);
		}
	}
}
