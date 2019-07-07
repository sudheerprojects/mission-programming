import shlex
MAG_IP_ADDRESS = {'ERD' : {'PDT' : '172.17.207.152', 'PRD' : '172.25.40.99'},
                  'FRA' : {'PDT' : '10.100.63.162', 'PRD' : '10.100.56.13'} }

i_data_centre = 'ERD'
i_phase = 'PDT'
i_var = 'ABC'
i_appli = 'TDS'
new_val = '12'

if i_appli is not None:
    app_be_get = "application=" + i_appli
    app_be_put = "\"application\":\"" + i_appli + "\""
else:
    app_be_get = "backend=" + i_be
    app_be_put = "\"backend\":\"" + i_be + "\""

cmd = "/home/pipapana/pwe/switchScripts/dist/accessMAG/accessMAG -m 'put' -U 'https://" + MAG_IP_ADDRESS[i_data_centre][i_phase] + ":10443/api/v1/objects/var' -d '{\"varibale\":\"" + i_var + "\", \"value\":\"" + new_val + "\", " +  app_be_put + "}'"
output = shlex.split(cmd)
print(output)
