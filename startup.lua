function startup()
	local config = {
		width = 640,
		height = 480,
		bpp = 32,
	}

	graphics.init(config.width, config.height, config.bpp)
	hello = graphics.loadImage("assets/hello.png")
end

function draw()
	graphics.drawImage(hello)
end

function run()
	while true do
		draw()
		graphics.show()
	end
end

startup()
run()
