package
{
	import flash.display.Sprite;
	//import flash.display.Bitmap;
	//import flash.net.URLLoader;
	import flash.net.URLRequest;
	//import flash.display.MovieClip;
	import flash.display.Loader;
	import flash.display.Stage;
	import flash.events.Event;
	import flash.events.KeyboardEvent;
	import flash.ui.Keyboard;
	
	public class Load_External_SWF extends Sprite
	{
		var mLoader:Loader = new Loader();
		
		public function Load_External_SWF()
		{
			stage.addEventListener(KeyboardEvent.KEY_DOWN, keyPressed);
			stage.addEventListener(KeyboardEvent.KEY_UP,   keyReleased);			
		}
		
		private function keyPressed(event:KeyboardEvent):void 
		{
			var key:uint = event.keyCode;
			switch (key) 
			{
			}
		}
		
		private function keyReleased(event:KeyboardEvent):void 
		{
			//unload content
			if (mLoader.content != null)
			{   
				mLoader.unload();
			}
			
			var key:uint = event.keyCode;
			switch (key) 
			{
				case Keyboard.B :
					playSWF("animations/B-bakri.swf");
					break;
				case Keyboard.C :
					playSWF("animations/C-charkhi.swf");
					break;
				case Keyboard.D :
					playSWF("animations/D-damdar.swf");
					break;
				case Keyboard.F :
					playSWF("animations/D-damdar.swf");
					break;
				case Keyboard.G :
					playSWF("animations/G-gamla.swf");
					break;
				case Keyboard.D :
					playSWF("animations/J-jahaj.swf");
					break;
				case Keyboard.D :
					playSWF("animations/K-kabutar.swf");
					break;
				case Keyboard.D :
					playSWF("animations/L-laddoo.swf");
					break;
				case Keyboard.D :
					playSWF("animations/M-makdi.swf");
					break;
				case Keyboard.D :
					playSWF("animations/N-nagar.swf");
					break;
				case Keyboard.D :
					playSWF("animations/P-pari.swf");
					break;
				case Keyboard.D :
					playSWF("animations/Sh-shatkon.swf");
					break;
				case Keyboard.D :
					playSWF("animations/T-tabla.swf");
					break;
				case Keyboard.D :
					playSWF("animations/V-van.swf");
					break;
			}
		}
		
		private function playSWF(fileName:String):void
		{
			var url:URLRequest = new URLRequest(fileName); 		// in this case both SWFs are in the same folder 
			mLoader.load(url);                                  // load the SWF file
			addChild(mLoader);                                  // add that instance to the display list, adding it to the Stage at 0,0
			
			// (optional)
			mLoader.x = 0;  	                                // move the loaded SWF 10 pixels to the right (from the left edge)   
			mLoader.y = 0;	                                    // move the loaded SWF 175 pixels down from the top
			
		}
	}
}