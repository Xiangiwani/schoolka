#!/usr/bin/env bash
# Installeert de back-up: bij opstarten, bij afsluiten en elke 10 minuten.
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
KEEP="${BACKUP_KEEP:-10}"
INTERVAL="${BACKUP_INTERVAL:-10min}"

install -d /opt/backup
install -m 755 "$(dirname "$0")/backup.py" /opt/backup/backup.py
sudo -u "$RUN_USER" mkdir -p "$SRC" "$DEST"

# 1. Back-up zelf (wordt gestart door de timer)
cat > /etc/systemd/system/backup.service <<EOT
[Unit]
Description=Back-up (zip)
RequiresMountsFor=$DEST

[Service]
Type=oneshot
User=$RUN_USER
Environment=BACKUP_SOURCE=$SRC
Environment=BACKUP_DEST=$DEST
Environment=BACKUP_KEEP=$KEEP
ExecStart=/usr/bin/python3 /opt/backup/backup.py
EOT

# 2. Timer: 30 sec na opstarten, daarna elke 10 minuten
cat > /etc/systemd/system/backup.timer <<EOT
[Unit]
Description=Back-up bij opstarten en elke $INTERVAL

[Timer]
OnBootSec=30s
OnUnitActiveSec=$INTERVAL

[Install]
WantedBy=timers.target
EOT

# 3. Back-up bij afsluiten (ExecStop draait tijdens het afsluiten)
cat > /etc/systemd/system/backup-shutdown.service <<EOT
[Unit]
Description=Back-up bij afsluiten
After=local-fs.target
RequiresMountsFor=$DEST

[Service]
Type=oneshot
RemainAfterExit=yes
User=$RUN_USER
Environment=BACKUP_SOURCE=$SRC
Environment=BACKUP_DEST=$DEST
Environment=BACKUP_KEEP=$KEEP
ExecStart=/bin/true
ExecStop=/usr/bin/python3 /opt/backup/backup.py
TimeoutStopSec=120

[Install]
WantedBy=multi-user.target
EOT

systemctl daemon-reload
systemctl enable --now backup.timer
systemctl enable --now backup-shutdown.service
systemctl start backup.service || true

echo
echo "Klaar: back-up bij opstarten, bij afsluiten en elke $INTERVAL (max $KEEP zips)."
echo "  Bron:  $SRC"
echo "  Doel:  $DEST"
echo "  Timer: systemctl list-timers | grep backup"
echo "  Log:   $DEST/backup.log"
