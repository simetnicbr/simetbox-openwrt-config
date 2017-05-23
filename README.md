# SIMETBox Config

Biblioteca para ler configuração do SIMETBox

## Instalação

No caso do uso do [SIMETBox Feed] [1], para os projetos OpenWRT e LEDE, esta biblioteca é baixada e usada de forma automática. Caso se queira compilar o projeto [simetbox-openwrt-base] [2] deve-se compilar este projeto separadamente:

[1]: https://github.com/simetnicbr/simetbox-openwrt-feed.git "SIMETBox Feed"
[2]: https://github.com/simetnicbr/simetbox-openwrt-feed.git "simetbox-openwrt-base"

```bash
git clone https://github.com/simetnicbr/simetbox-openwrt-base.git
cd simetbox-openwrt-base
autoreconf
automake --add-missing
./configure
make install
```

## Uso

É usado pelo projeto simetbox-openwrt-base

## History

2013-05-23 - Primeiro release

## Credits

NIC.br  
<medicoes@simet.nic.br>

## License

GPL-2