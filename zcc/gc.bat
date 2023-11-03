@echo off
cls

rem Delete all
erase /Q .\assets\*.*
erase bank*.*

bmp2tile .\gfx\exittilesa.png -savetiles .\assets\exittilesa.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\forbidtilesa.png -savetiles .\assets\forbidtilesa.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\exittilesb.png -savetiles .\assets\exittilesb.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\forbidtilesb.png -savetiles .\assets\forbidtilesb.bin -noremovedupes -nomirror -exit

rem images
bmp2tile .\gfx\balout.png -savetiles .\assets\balout.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\machine.png -savetiles .\assets\machine.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\missile.png -savetiles .\assets\missile.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\vault.png -savetiles .\assets\vault.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\blobc.png -savetiles .\assets\blobc.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\gusana.png -savetiles .\assets\gusana.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\gusanb.png -savetiles .\assets\gusanb.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\gusanc.png -savetiles .\assets\gusanc.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\mymaster.png -savetiles .\assets\mymaster.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\bigdouble.png -savetiles .\assets\bigdouble.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\bigboss.png -savetiles .\assets\bigboss.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\bigblob.png -savetiles .\assets\bigblob.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\basepinch.png -savetiles .\assets\basepinch.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\bigrobot2.png -savetiles .\assets\bigrobot2.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\blob.png -savetiles .\assets\blob.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\blobb.png -savetiles .\assets\blobb.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\flyingrobot.png -savetiles .\assets\flyingrobot.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\littlepinch.png -savetiles .\assets\littlepinch.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\pinch.png -savetiles .\assets\pinch.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\rollingrobot0.png -savetiles .\assets\rollingrobot0.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\skull.png -savetiles .\assets\skull.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\laser.png -savetiles .\assets\laser.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\soldierdown.png -savetiles .\assets\soldierdown.bin -noremovedupes -nomirror -exit

bmp2tile .\gfx\liftscroll.png -savetiles .\assets\liftscroll.bin -noremovedupes -nomirror -exit

bmp2tile .\gfx\clothes.png -savetiles .\assets\clothes.bin -exit
bmp2tile .\gfx\change0.png -savetiles .\assets\change0.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\change1.png -savetiles .\assets\change1.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\change2.png -savetiles .\assets\change2.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\change3.png -savetiles .\assets\change3.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\change4.png -savetiles .\assets\change4.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\change5.png -savetiles .\assets\change5.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\change6.png -savetiles .\assets\change6.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\change7.png -savetiles .\assets\change7.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\changeclosed.png -savetiles .\assets\changeclosed.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\planetslide.png -savetiles .\assets\planetslide.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\bigexplosion.png -savetiles .\assets\bigexplosion.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\coin.png -savetiles .\assets\coin.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\numbers.png -savetiles .\assets\numbers.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\cursors.png -savetiles .\assets\cursors.bin -noremovedupes -nomirror -exit
bmp2tile.exe .\gfx\font.png -savetiles .\assets\font.bin -nomirror -exit
bmp2tile .\gfx\littleexplosion.png -savetiles .\assets\littleexplosion.bin -noremovedupes -nomirror -exit
bmp2tile.exe .\gfx\logo.png -savetiles .\assets\logotiles.bin -removedupes -tileoffset 256 -savetilemap .\assets\logotilemap.bin -exit
bmp2tile.exe .\gfx\about.png -savetiles .\assets\abouttiles.bin -removedupes -tileoffset 256 -savetilemap .\assets\abouttilemap.bin -savepalette .\assets\aboutpalette.bin -exit
bmp2tile.exe .\gfx\mikgames.png -savetiles .\assets\mikgamestiles.bin -removedupes -tileoffset 256 -savetilemap .\assets\mikgamestilemap.bin -exit
bmp2tile.exe .\gfx\introbackground1.png -savetiles .\assets\introtiles1.bin -removedupes -tileoffset 256 -savetilemap .\assets\introtilemap1.bin -exit
bmp2tile.exe .\gfx\introbackground2.png -savetiles .\assets\introtiles2.bin -removedupes -tileoffset 256 -savetilemap .\assets\introtilemap2.bin -exit
bmp2tile .\gfx\platform.png -savetiles .\assets\platform.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\player.png -savetiles .\assets\player.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playerb.png -savetiles .\assets\playerb.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playerc.png -savetiles .\assets\playerc.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playerd.png -savetiles .\assets\playerd.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playerdb.png -savetiles .\assets\playerdb.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playerfall.png -savetiles .\assets\playerfall.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playerfallb.png -savetiles .\assets\playerfallb.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playerfallc.png -savetiles .\assets\playerfallc.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playerfalld.png -savetiles .\assets\playerfalld.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playerindicator.png -savetiles .\assets\playerindicator.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\enemyshoot.png -savetiles .\assets\enemyshoot.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playershoot.png -savetiles .\assets\playershoot.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playershootb.png -savetiles .\assets\playershootb.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playershootc.png -savetiles .\assets\playershootc.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\playershootd.png -savetiles .\assets\playershootd.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\shadow.png -savetiles .\assets\shadow.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\introboss.png -savetiles .\assets\introboss.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\introship.png -savetiles .\assets\introship.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\introlittleship.png -savetiles .\assets\introlittleship.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\introflyingman.png -savetiles .\assets\introflyingman.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\introflyingmanb.png -savetiles .\assets\introflyingmanb.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\introtheend.png -savetiles .\assets\introtheend.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\introstar.png -savetiles .\assets\introstar.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\facegusan.png -savetiles .\assets\facegusan.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\facebigdouble.png -savetiles .\assets\facebigdouble.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\facebigboss.png -savetiles .\assets\facebigboss.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\facebigblob.png -savetiles .\assets\facebigblob.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\faceplayerintro.png -savetiles .\assets\faceplayerintro.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\faceplayerleft.png -savetiles .\assets\faceplayerleft.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\faceplayerright.png -savetiles .\assets\faceplayerright.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\facerobot.png -savetiles .\assets\facerobot.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\facemike.png -savetiles .\assets\facemike.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\stage3animtilesa.png -savetiles .\assets\stage3animtilesa.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\stage3animtilesb.png -savetiles .\assets\stage3animtilesb.bin -noremovedupes -nomirror -exit
bmp2tile .\gfx\stage1animtiles.png -savetiles .\assets\stage1animtiles.bin -noremovedupes -nomirror -exit

bmp2tile .\gfx\baloutfield.png -savetilemap .\assets\baloutfield.bin -removedupes -mirror -exit
bmp2tile .\gfx\balouttitle.png -savetilemap .\assets\balouttitle.bin -removedupes -mirror -exit

rem Sounds
copy sfx\baloutbso.psg assets
copy sfx\silence.psg assets
copy sfx\warp.psg assets
copy sfx\gameover.psg assets
copy sfx\pause.psg assets
copy sfx\talk.psg assets
copy sfx\explosion.psg assets
copy sfx\jump.psg assets
copy sfx\shoot.psg assets
copy sfx\shop.psg assets
copy sfx\intro.psg assets
copy sfx\stage1.psg assets
copy sfx\stage2.psg assets
copy sfx\stage3.psg assets
copy sfx\stage4.psg assets
copy sfx\boss.psg assets
copy sfx\ending.psg assets
copy sfx\littleships.psg assets
copy sfx\introlaser.psg assets
copy sfx\damage.psg assets
copy sfx\intro2.psg assets
copy sfx\fall.psg assets
copy sfx\heart.psg assets
copy sfx\coin.psg assets
copy sfx\laser.psg assets

rem Maps
cd tmx

rem Tiles for the entire game
bmp2tile stage3tiles.png -savetiles ..\assets\stage3tiles.bin -removedupes -savetilemap ..\stage3tilesmapping.bin -exit
bmp2tile stage1tiles.png -savetiles ..\assets\stage1tiles.bin -removedupes -savetilemap ..\stage1tilesmapping.bin -exit

rem Stages
csvtobin stage1.csv stage1tilemap.bin
move stage1tilemap.bin ..\assets

csvtobin stage2.csv stage2tilemap.bin
move stage2tilemap.bin ..\assets

csvtobin stage3.csv stage3tilemap.bin
move stage3tilemap.bin ..\assets

csvtobin stage4.csv stage4tilemap.bin
move stage4tilemap.bin ..\assets

csvtobin stage5.csv stage5tilemap.bin
move stage5tilemap.bin ..\assets

csvtobin stage6.csv stage6tilemap.bin
move stage6tilemap.bin ..\assets

csvtobin stage7.csv stage7tilemap.bin
move stage7tilemap.bin ..\assets

csvtobin stage8.csv stage8tilemap.bin
move stage8tilemap.bin ..\assets

csvtobin stage9.csv stage9tilemap.bin
move stage9tilemap.bin ..\assets

csvtobin stage10.csv stage10tilemap.bin
move stage10tilemap.bin ..\assets

csvtobin stage11.csv stage11tilemap.bin
move stage11tilemap.bin ..\assets

csvtobin stage12.csv stage12tilemap.bin
move stage12tilemap.bin ..\assets

csvtobin stage13.csv stage13tilemap.bin
move stage13tilemap.bin ..\assets

csvtobin stage14.csv stage14tilemap.bin
move stage14tilemap.bin ..\assets

csvtobin stage15.csv stage15tilemap.bin
move stage15tilemap.bin ..\assets

csvtobin stage16.csv stage16tilemap.bin
move stage16tilemap.bin ..\assets

csvtobin stage17.csv stage17tilemap.bin
move stage17tilemap.bin ..\assets

csvtobin stage18.csv stage18tilemap.bin
move stage18tilemap.bin ..\assets

cd ..

rem Fix tilemappings
erase stage3tilesmapping.bin.h
bin2header stage3tilesmapping.bin
erase stage3tilesmapping.bin

erase stage1tilesmapping.bin.h
bin2header stage1tilesmapping.bin
erase stage1tilesmapping.bin

rem Goto Assets
cd assets

rem Compression
zx7 balout.bin balout.zx7
zx7 machine.bin machine.zx7
zx7 missile.bin missile.zx7
zx7 vault.bin vault.zx7
zx7 blobc.bin blobc.zx7
zx7 gusana.bin gusana.zx7
zx7 gusanb.bin gusanb.zx7
zx7 gusanc.bin gusanc.zx7
zx7 mymaster.bin mymaster.zx7
zx7 bigdouble.bin bigdouble.zx7
zx7 bigboss.bin bigboss.zx7
zx7 bigblob.bin bigblob.zx7
zx7 basepinch.bin basepinch.zx7
zx7 bigrobot2.bin bigrobot2.zx7
zx7 blob.bin blob.zx7
zx7 blobb.bin blobb.zx7
zx7 flyingrobot.bin flyingrobot.zx7
zx7 littlepinch.bin littlepinch.zx7
zx7 pinch.bin pinch.zx7
zx7 rollingrobot0.bin rollingrobot0.zx7
zx7 skull.bin skull.zx7
zx7 laser.bin laser.zx7
zx7 soldierdown.bin soldierdown.zx7

zx7 forbidtilesa.bin forbidtilesa.zx7
zx7 exittilesa.bin exittilesa.zx7
zx7 forbidtilesb.bin forbidtilesb.zx7
zx7 exittilesb.bin exittilesb.zx7

zx7 clothes.bin clothes.zx7
zx7 change0.bin change0.zx7
zx7 change1.bin change1.zx7
zx7 change2.bin change2.zx7
zx7 change3.bin change3.zx7
zx7 change4.bin change4.zx7
zx7 change5.bin change5.zx7
zx7 change6.bin change6.zx7
zx7 change7.bin change7.zx7
zx7 changeclosed.bin changeclosed.zx7
zx7 planetslide.bin planetslide.zx7
zx7 bigexplosion.bin bigexplosion.zx7
zx7 coin.bin coin.zx7
zx7 numbers.bin numbers.zx7
zx7 cursors.bin cursors.zx7
zx7 font.bin font.zx7
zx7 littleexplosion.bin littleexplosion.zx7
zx7 logotiles.bin logotiles.zx7
zx7 logotilemap.bin logotilemap.zx7
zx7 abouttiles.bin abouttiles.zx7
zx7 abouttilemap.bin abouttilemap.zx7
zx7 mikgamestiles.bin mikgamestiles.zx7
zx7 mikgamestilemap.bin mikgamestilemap.zx7
zx7 player.bin player.zx7
zx7 playerb.bin playerb.zx7
zx7 playerc.bin playerc.zx7
zx7 playerd.bin playerd.zx7
zx7 playerdb.bin playerdb.zx7
zx7 playerfall.bin playerfall.zx7
zx7 playerfallb.bin playerfallb.zx7
zx7 playerfallc.bin playerfallc.zx7
zx7 playerfalld.bin playerfalld.zx7
zx7 platform.bin platform.zx7
zx7 playerindicator.bin playerindicator.zx7
zx7 enemyshoot.bin enemyshoot.zx7
zx7 playershoot.bin playershoot.zx7
zx7 playershootb.bin playershootb.zx7
zx7 playershootc.bin playershootc.zx7
zx7 playershootd.bin playershootd.zx7
zx7 shadow.bin shadow.zx7
zx7 introboss.bin introboss.zx7
zx7 introship.bin introship.zx7
zx7 introlittleship.bin introlittleship.zx7
zx7 introflyingman.bin introflyingman.zx7
zx7 introflyingmanb.bin introflyingmanb.zx7
zx7 introtheend.bin introtheend.zx7
zx7 introstar.bin introstar.zx7
zx7 introtiles1.bin introtiles1.zx7
zx7 introtilemap1.bin introtilemap1.zx7
zx7 introtiles2.bin introtiles2.zx7
zx7 introtilemap2.bin introtilemap2.zx7

zx7 facegusan.bin facegusan.zx7
zx7 facebigdouble.bin facebigdouble.zx7
zx7 facebigboss.bin facebigboss.zx7
zx7 facebigblob.bin facebigblob.zx7
zx7 faceplayerintro.bin faceplayerintro.zx7
zx7 faceplayerleft.bin faceplayerleft.zx7
zx7 faceplayerright.bin faceplayerright.zx7
zx7 facerobot.bin facerobot.zx7
zx7 facemike.bin facemike.zx7

zx7 stage3tiles.bin stage3tiles.zx7
zx7 stage1tiles.bin stage1tiles.zx7

zx7 stage1tilemap.bin stage1tilemap.zx7
zx7 stage2tilemap.bin stage2tilemap.zx7
zx7 stage3tilemap.bin stage3tilemap.zx7
zx7 stage4tilemap.bin stage4tilemap.zx7
zx7 stage5tilemap.bin stage5tilemap.zx7
zx7 stage6tilemap.bin stage6tilemap.zx7
zx7 stage7tilemap.bin stage7tilemap.zx7
zx7 stage8tilemap.bin stage8tilemap.zx7
zx7 stage9tilemap.bin stage9tilemap.zx7
zx7 stage10tilemap.bin stage10tilemap.zx7
zx7 stage11tilemap.bin stage11tilemap.zx7
zx7 stage12tilemap.bin stage12tilemap.zx7
zx7 stage13tilemap.bin stage13tilemap.zx7
zx7 stage14tilemap.bin stage14tilemap.zx7
zx7 stage15tilemap.bin stage15tilemap.zx7
zx7 stage16tilemap.bin stage16tilemap.zx7
zx7 stage17tilemap.bin stage17tilemap.zx7
zx7 stage18tilemap.bin stage18tilemap.zx7

rem Deletion

erase balout.bin
erase machine.bin
erase missile.bin
erase vault.bin
erase blobc.bin
erase gusana.bin
erase gusanb.bin
erase gusanc.bin
erase mymaster.bin
erase bigdouble.bin
erase bigboss.bin
erase bigblob.bin
erase basepinch.bin
erase bigrobot2.bin
erase blob.bin
erase blobb.bin
erase flyingrobot.bin
erase littlepinch.bin
erase pinch.bin
erase rollingrobot0.bin
erase skull.bin
erase laser.bin
erase soldierdown.bin

erase forbidtilesa.bin
erase exittilesa.bin
erase forbidtilesb.bin
erase exittilesb.bin

erase clothes.bin
erase change0.bin
erase change1.bin
erase change2.bin
erase change3.bin
erase change4.bin
erase change5.bin
erase change6.bin
erase change7.bin
erase changeclosed.bin
erase planetslide.bin
erase bigexplosion.bin
erase coin.bin
erase numbers.bin
erase cursors.bin
erase font.bin
erase littleexplosion.bin
erase logotiles.bin
erase logotilemap.bin
erase abouttiles.bin
erase abouttilemap.bin
erase mikgamestiles.bin
erase mikgamestilemap.bin
erase player.bin
erase playerb.bin
erase playerc.bin
erase playerd.bin
erase playerdb.bin
erase playerfall.bin
erase playerfallb.bin
erase playerfallc.bin
erase playerfalld.bin
erase platform.bin
erase playerindicator.bin
erase enemyshoot.bin
erase playershoot.bin
erase playershootb.bin
erase playershootc.bin
erase playershootd.bin
erase shadow.bin
erase introboss.bin
erase introship.bin
erase introlittleship.bin
erase introflyingman.bin
erase introflyingmanb.bin
erase introtheend.bin
erase introstar.bin
erase introtiles1.bin
erase introtilemap1.bin
erase introtiles2.bin
erase introtilemap2.bin

erase facegusan.bin
erase facebigdouble.bin
erase facebigboss.bin
erase facebigblob.bin
erase faceplayerintro.bin
erase faceplayerleft.bin
erase faceplayerright.bin
erase facerobot.bin
erase facemike.bin

erase stage3tiles.bin
erase stage1tiles.bin

erase stage1tilemap.bin
erase stage2tilemap.bin
erase stage3tilemap.bin
erase stage4tilemap.bin
erase stage5tilemap.bin
erase stage6tilemap.bin
erase stage7tilemap.bin
erase stage8tilemap.bin
erase stage9tilemap.bin
erase stage10tilemap.bin
erase stage11tilemap.bin
erase stage12tilemap.bin
erase stage13tilemap.bin
erase stage14tilemap.bin
erase stage15tilemap.bin
erase stage16tilemap.bin
erase stage17tilemap.bin
erase stage18tilemap.bin

rem Exit 
cd ..

rem Banks conversion
assets2banks assets

