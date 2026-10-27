#!/usr/bin/env bash
# Installeert het back-upscript en laat het automatisch starten bij het opstarten (systemd).
# Gebruik:  sudo ./install.sh
set -euo pipefail

if [ "$EUID" -ne 0 ]; then
  echo "Start met sudo:  sudo ./install.sh" >&2
  exit 1
fi

RUN_USER="${SUDO_USER:-pi}"
HOME_DIR="$(getent passwd "$RUN_USER" | cut -d: -f6)"
SRC="${BACKUP_SOURCE:-$HOME_DIR/Documenten}"
DEST="${BACKUP_DEST:-$HOME_DIR/backup}"
KEEP="${BACKUP_KEEP:-5}"

# 1. Script installeren
install -d /opt/backup
install -m 755 "$(dirname "$0")/backup.py" /opt/backup/backup.py

# 2. Bron- en doelmap aanmaken
sudo -u "$RUN_USER" mkdir -p "$SRC" "$DEST"

# 3. systemd-service aanmaken
cat > /etc/systemd/system/backup.service <<EOF
[Unit]
Description=Automatische back-up (zip) bij het opstarten
After=local-fs.target network.target
# Bij een USB-stick: zet hier RequiresMountsFor=/media/pi/USB
RequiresMountsFor=$DEST

[Service]
Type=oneshot
User=$RUN_USER
Environment=BACKUP_SOURCE=$SRC
Environment=BACKUP_DEST=$DEST
Environment=BACKUP_KEEP=$KEEP
ExecStart=/usr/bin/python3 /opt/backup/backup.py

[Install]
WantedBy=multi-user.target
EOF

# 4. Inschakelen en meteen testen
systemctl daemon-reload
systemctl enable backup.service
systemctl start backup.service || true

echo
echo "Klaar. Back-up draait nu bij elke start."
echo "  Bron:   $SRC"
echo "  Doel:   $DEST"
echo "  Status: systemctl status backup.service"
echo "  Log:    $DEST/backup.log"
