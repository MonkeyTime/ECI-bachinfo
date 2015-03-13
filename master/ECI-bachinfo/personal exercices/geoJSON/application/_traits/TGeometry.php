<?php

trait TGeometry {
	
	/**
	 * getValueMember
	 * 
	 * @todo To test - not sure on the result when namespace is in use
	 * 
	 * @return string
	 */
	public function getValueMember() {
		
		return get_class();
		
	/* @todo

		$class = __CLASS__;
		
		return get_class(new $class);
	*/
	}
	
	public function getKeyMember() {
		
		return 'type';
	}
}