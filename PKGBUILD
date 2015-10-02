pkgname=dwm
pkgver=6.0
pkgrel=4
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama' 'pango')
install=dwm.install
source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
	dwm.desktop
	config.h
  	gaplessgrid.c
	maximize.c)

_patches=(00-dwm-6.0-buildflags.diff
	  01-dwm-6.0-xft.diff
	  02-dwm-6.0-pertag2.diff
	  03-dwm-6.0-betterborders.diff
	  04-dwm-6.0-systray.diff
	  05-dwm-6.0-statuscolors.diff
	  06-dwm-6.0-monocle_fixes.diff
	  07-dwm-6.0-maximize.diff
	  08-dwm-6.0-swapfocus.diff
	  09-dwm-6.0-cycle.diff
	  10-dwm-6.0-moveresize.diff
	  11-dwm-6.0-XKeycodeToKeysym_fix.diff
	  12-dwm-6.0-pangofix.diff)

source=(${source[@]} ${_patches[@]})

build() {
  cd $srcdir/$pkgname-$pkgver


  for p in "${_patches[@]}"; do
    echo "=> $p"
    patch -Np1 < ../$p || return 1
  done

  cp $srcdir/config.h config.h
  cp $srcdir/gaplessgrid.c gaplessgrid.c
  cp $srcdir/maximize.c maximize.c

  sed -i 's/CPPFLAGS =/CPPFLAGS +=/g' config.mk
  sed -i 's/^CFLAGS = -g/#CFLAGS += -g/g' config.mk
  sed -i 's/^#CFLAGS = -std/CFLAGS += -std/g' config.mk
  sed -i 's/^LDFLAGS = -g/#LDFLAGS += -g/g' config.mk
  sed -i 's/^#LDFLAGS = -s/LDFLAGS += -s/g' config.mk
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd $srcdir/$pkgname-$pkgver
  make PREFIX=/usr DESTDIR=$pkgdir install
  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
  install -m644 -D $srcdir/dwm.desktop $pkgdir/usr/share/xsessions/dwm.desktop
}
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '939f403a71b6e85261d09fc3412269ee'
         'ed911967a976a77f08e0e3e5ad107525'
         '4ba509b3b93f7b1418dc703c70de536f'
         '015213049aa1fdf6d489348d44df05df'
         '09e3586f19d5d5d59379bab3d8d512ff'
         'ce52e9da51fea4d44e217441b1159452'
         '65c410a0fae5704a0dcba8a76f86ced1'
         '3f038ce43e1e6632ee962cb6a2478136'
         '77e623c7211a00649cba6d100557d772'
         '2ab833f04ac52857d876140e6417141e'
         'a2b5590490d1971dac76c839e2ad83e1'
         '13cb3f721439f9f3b44be88c6341c957'
         'dba56f36c523ed6cb76b1ade4d400b9e'
         '16eff41cd00cedc784182738f9571f2e'
         'b55559273de593fa49ffc4fc6f71ca57'
         'd3fc44b5f41f70d03aca1411d3b8d7aa'
         '21a36ad97a4fb23b6d1224e44d9b9c1f')
