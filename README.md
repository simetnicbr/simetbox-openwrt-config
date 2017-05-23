# SIMETBox Config

Biblioteca para ler configuração do SIMETBox

## Instalação

No caso do uso do [SIMETBox Feed](https://github.com/simetnicbr/simetbox-openwrt-feed.git), para os projetos OpenWRT e LEDE, esta biblioteca é baixada e usada de forma automática. Caso se queira compilar o projeto [simetbox-openwrt-base](https://github.com/simetnicbr/simetbox-openwrt-base.git) deve-se compilar este projeto separadamente:

```bash
git clone https://github.com/simetnicbr/simetbox-openwrt-config.git
cd simetbox-openwrt-config
autoreconf
automake --add-missing
./configure
make install
```

## Uso

É usado pelo projeto simetbox-openwrt-base

## History

2017-05-23 - Primeiro release

## Credits

NIC.br  
<medicoes@simet.nic.br>

## License

GPL-2