package
{
	import flash.display.Sprite;
	//import flash.display.Bitmap;
	//import flash.net.URLLoader;
	import flash.net.URLRequest;
	//import flash.display.MovieClip;
	import flash.display.Loader;
	
	public class Load_External_SWF extends Sprite
	{
		public function Load_External_SWF()
		{
			//var loader:SWFLoader = new SWFLoader();
			var myLoader:Loader = new Loader();                     // create a new instance of the Loader class
			var url:URLRequest = new URLRequest("ExternalSWF.swf"); // in this case both SWFs are in the same folder 
			myLoader.load(url);                                     // load the SWF file
			addChild(myLoader);                                     // add that instance to the display list, adding it to the Stage at 0,0
			
			// (optional)
			myLoader.x = 10;                                        // move the loaded SWF 10 pixels to the right (from the left edge)   
			myLoader.y = 175;                                       // move the loaded SWF 175 pixels down from the top
			
			// (optional) load a second external SWF file
			var my2ndLoader:Loader = new Loader();
			var url2:URLRequest = new URLRequest("ExternalSWF2.swf");
			my2ndLoader.load(url2);
			addChild(my2ndLoader);                                  // optionally, you could put the 2nd SWF beneath 
			// the 1st by using addChildAt(my2ndLoader, 1);
			// displacing the 1st SWF from position 1 to 2 in the display list
			
			// (optional) scaling of the 2nd SWF file
			my2ndLoader.scaleX = 2;                                 // scale the SWF horizontally by 200%
			my2ndLoader.scaleY = 2;                                 // scale the SWF vertically by 200%
		}
	}
}