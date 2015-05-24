#!/usr/bin/env python
import smtplib
import email.utils
from email.mime.text import MIMEText
from email.Header import Header

server = smtplib.SMTP('192.168.74.136')

msg = MIMEText('This is thd body of the message')
msg['To'] = 'zms@zms.name'
msg['From'] = '251250980@qq.com'
msg['Sbuject'] = 'Simple text message'
#msg['To'] = email.utils.formataddr(('Recipient', '251250980@qq.com'))
#msg['From'] = email.utils.formataddr(('Author', 'baotiao@gmail.com'))
#msg['Subject'] = 'Simple text message'

#server = smtplib.SMTP('mail')
server.set_debuglevel(True)
try:
    server.sendmail(msg['From'], ['251250980@qq.com'], msg.as_string())
finally:
    server.quit()

